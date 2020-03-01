#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#include <semaphore.h>

using namespace std;

int _maxToken, _flowInterval;

class Queue
{
  public:
    Queue()
    {
        start = 0;
        end = 0;
        sequenceNum = 0;
    }

    int len()
    {
        return end - start;
    }

    int enqueue(int num)
    {
        end += num;
        sequenceNum += num;

        if (len() > 50)
        {
            int length = len();
            end = start + 50;
            return length - end;
        }
        return 0;
    }

    int dequeue(int num)
    {
        if (start + num > end)
        {
            int servedCount = end - start;
            start = end;
            return servedCount;
        }
        else
        {
            start += num;
            return num;
        }
    }

    int back()
    {
        return sequenceNum - 1;
    }

  private:
    int start;
    int end;
    int sequenceNum;
};

struct ParameterPasser
{
    int MaxToken;
    Queue *q;
};

int servedToken = 0;
int totalDropped = 0;
int totalFetched = 0;
int totalGeneratedByFlow = 0;
int totalGeneratedByPflow = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t mtx2 = PTHREAD_MUTEX_INITIALIZER;
sem_t pflowSem;

void *pflowSubroutine(void *queue)
{

    Queue *tokenQ = ((Queue *)queue);
    int temp;
    int lockingResult;

    while (servedToken < _maxToken)
    {
        int waitSemState = sem_wait(&pflowSem);
        if (waitSemState != 0)
        {
            cout << "Failed to increament semaphore value." << endl;
            exit(-1);
        }
        if (servedToken >= _maxToken)
            break;
        int randNum = floor(rand() % 5 + 1);
        lockingResult = pthread_mutex_lock(&mtx);
        if (lockingResult)
        {
            cout << "Failed to lock mutex" << endl;
            exit(-1);
        }
        lockingResult = pthread_mutex_lock(&mtx2);
        if (lockingResult)
        {
            cout << "Failed to lock mutex2" << endl;
            exit(-1);
        }

        int dropped = tokenQ->enqueue(randNum);
        totalGeneratedByPflow += randNum;
        servedToken += dropped;
        totalDropped += dropped;
        if (servedToken > _maxToken)
        {
            int diffToken = servedToken - _maxToken;
            totalDropped -= diffToken;
            servedToken = _maxToken;
        }

        cout << randNum << "(pflow)\t" << tokenQ->back() << "\t\t\t" << tokenQ->len() << endl;
        // cout << "Flow Wake Up. Generated : " << randNum <<", Dropped :" <<dropped << ", queueLen : " <<tokenQ->len()<< endl;
        lockingResult = pthread_mutex_unlock(&mtx2);
        if (lockingResult)
        {
            cout << "Failed to unlock mutex2" << endl;
            exit(-1);
        }
        lockingResult = pthread_mutex_unlock(&mtx);
        if (lockingResult)
        {
            cout << "Failed to unlock mutex" << endl;
            exit(-1);
        }

        
    }
}

//TODO: fix problem of over dropped
void *flowSubroutine(void *queue)
{
    Queue *tokenQ = ((Queue *)queue);
    int temp;
    int lockingResult;
    // int totalDropped = 0;
    // int totalGenerated = 0;
    while (servedToken < _maxToken)
    {
        sleep(_flowInterval);
        if (servedToken >= _maxToken)
            break;

        lockingResult = pthread_mutex_lock(&mtx);
        if (lockingResult)
        {
            cout << "Failed to lock mutex" << endl;
            exit(-1);
        }
lockingResult = pthread_mutex_lock(&mtx2);
        if (lockingResult)
        {
            cout << "Failed to lock mutex2" << endl;
            exit(-1);
        }


        int randNum = floor(rand() % 10 + 1);

        int dropped = tokenQ->enqueue(randNum);
        totalGeneratedByFlow += randNum;
        servedToken += dropped;
        totalDropped += dropped;
        if (servedToken > _maxToken)
        {
            int diffToken = servedToken - _maxToken;
            totalDropped -= diffToken;
            servedToken = _maxToken;
        }

        cout << randNum << "(flow) \t" << tokenQ->back() << "\t\t\t" << tokenQ->len() << endl;
        // cout << "Flow Wake Up. Generated : " << randNum <<", Dropped :" <<dropped << ", queueLen : " <<tokenQ->len()<< endl;
        lockingResult = pthread_mutex_unlock(&mtx2);
        if (lockingResult)
        {
            cout << "Failed to unlock mutex2" << endl;
            exit(-1);
        }
        lockingResult = pthread_mutex_unlock(&mtx);
        if (lockingResult)
        {
            cout << "Failed to unlock mutex" << endl;
            exit(-1);
        }
    }
    pthread_exit(0);
}

void *serverSubroutine(void *queue)
{
    Queue *tokenQ = ((Queue *)queue);
    int lockingResult;
    while (servedToken < _maxToken)
    {
        sleep(2);

        if (servedToken >= _maxToken)
            break;

        lockingResult = pthread_mutex_lock(&mtx);
        if (lockingResult)
        {
            cout << "Failed to lock mutex" << endl;
            exit(-1);
        }

        int randNum = floor(rand() % 20 + 1);

        if (randNum + servedToken > _maxToken)
        {
            randNum = _maxToken - servedToken;
        }

        int served = tokenQ->dequeue(randNum);
        servedToken += served;
        totalFetched += served;

        cout << "\t\t\t\t\t" << tokenQ->len() << "\t\t" << served << "\t\t" << totalFetched << endl;

        int value;
        int getSemState = sem_getvalue(&pflowSem, &value);
        if (getSemState != 0)
        {
            cout << "Failed to get semaphore value." << endl;
            exit(-1);
        }
        if (tokenQ->len() == 0 && value == 0)
        {
            int postSemState = sem_post(&pflowSem);
            if (postSemState != 0)
            {
                cout << "Failed to increament semaphore value." << endl;
                exit(-1);
            }
        }

        lockingResult = pthread_mutex_unlock(&mtx);
        if (lockingResult)
        {
            cout << "Failed to unlock mutex" << endl;
            exit(-1);
        }
    }
    int postSemState = sem_post(&pflowSem);
    if (postSemState != 0)
    {
        cout << "Failed to increament semaphore value." << endl;
        exit(-1);
    }
    pthread_exit(0);
}

void initThreads()
{
    pthread_t flow_thread, server_thread, pflow_thread;

    int *c;
    float *d;
    void *a[] = {c, d};

    int initState = sem_init(&pflowSem, 0, 0);
    if (initState != 0)
    {
        cout << "Failed to initialise semaphore." << endl;
        exit(-1);
    }

    Queue *q = new Queue();

    int returnValue = pthread_create(&server_thread, NULL, serverSubroutine, q);
    if (returnValue)
    {
        cout << "Failed to create server thread." << endl;
        exit(-1);
    }

    returnValue = pthread_create(&flow_thread, NULL, flowSubroutine, q);
    if (returnValue)
    {
        cout << "Failed to create flow thread." << endl;
        exit(-1);
    }

    returnValue = pthread_create(&pflow_thread, NULL, pflowSubroutine, q);
    if (returnValue)
    {
        cout << "Failed to create pflow thread." << endl;
        exit(-1);
    }

    returnValue = pthread_join(server_thread, NULL);
    if (returnValue)
    {
        cout << "Failed to join server thread." << endl;
        exit(-1);
    }
    returnValue = pthread_join(flow_thread, NULL);
    if (returnValue)
    {
        cout << "Failed to join flow thread." << endl;
        exit(-1);
    }
    returnValue = pthread_join(pflow_thread, NULL);
    if (returnValue)
    {
        cout << "Failed to join pflow thread." << endl;
        exit(-1);
    }

    cout << "The total number of tokens that have been fetched by the server is " << totalFetched << endl;
    cout << "The total number of tokens that have been generated by the flow is " << totalGeneratedByFlow << endl;
    cout << "The total number of tokens that have been generated by the pflow is " << totalGeneratedByPflow << endl;
    cout << "The total number of tokens that have been dropped by the queue is " << totalDropped << endl;
}

int main(int input_size, char **external_input)
{
    if (input_size > 2)
    {

        _maxToken = atoi(external_input[1]);
        _flowInterval = atoi(external_input[2]);

        cout << "The Max Token is " << _maxToken << " and the interval time for flow is " << _flowInterval << endl;
        cout << "Flow\t\t\t\t\tQueue\t\tServer" << endl;
        cout << "Token added\tLast sequence number\tCurrent length\tToken fetched\tTotal Token fetched" << endl;
        initThreads();
    }
    else
    {
        cout << "Please provide parameter prior starting.\nfirst(MaxToken) second(flowInterval)" << endl;
        exit(-1);
    }
    return 0;
}
