public class Audio extends Entry implements Non_visual, Playable {

    private double duration;
    private double size;

    public Audio(String n, double dur, double s)  /* constructor */
    {
        super(n);  /* calls entry class*/
        duration = dur;
        size  = s;
    }

    public double get_duration()
    {
        return duration;  /* returns duration */
    }

    public double get_size()
    {
        return size;  /* returns size */
    }

    @Override
    public void info()  /* writes object informations */
    {
        System.out.println("Audio name: " + super.getName());
        System.out.println("duration: " + get_duration());
        System.out.println("size: " + get_size());
    }

}
//