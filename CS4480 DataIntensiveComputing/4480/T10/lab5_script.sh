start-dfs.sh
start-yarn.sh
mr-jobhistory-daemon.sh start historyserver
jps
hdfs dfs -put clustering_dataset.txt
spark-1.1.0-bin-hadoop2.4/bin/spark-shell -i kmeans_potentialAnswer.scala
