
public class Phone
{
    private double battery;
    
    public Phone()
    {
        battery = 1.0;
    }
    
    public double getBattery(){
        return this.battery;
    }
    
    public void be_played_for(int hour){
        battery = battery - hour *0.2;
        if(battery <0)
            battery=0;
    }
    
    public void be_charged_for(int hour){
        battery = battery + hour * 0.5;
        if (battery > 1){
            battery = 1;
        }
    }
    
    public void be_played_music_for(int hour){
        double musicBattery = hour *0.1;
        System.out.printf("%d-hour music playing consumes %.2f battery\n", hour, musicBattery);
        battery = battery - musicBattery;
        if (battery < 0){
            battery =0;
        }
    }

}
