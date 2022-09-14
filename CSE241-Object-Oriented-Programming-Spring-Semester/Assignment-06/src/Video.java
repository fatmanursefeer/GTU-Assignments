public class Video extends Entry implements Visual, Playable {

    private double duration;
    private int dimension;

    public Video(String n, double dur, int dim)  /* constructor */
    {
        super(n);  /* calls entry class*/
        duration = dur;
        dimension = dim;
    }

    public double get_duration()
    {
        return duration;  /* returns duration */
    }

    public int get_dimension()
    {
        return dimension;  /* returns dimension */
    }

    @Override
    public void info()  /* writes object informations */
    {
        System.out.println("Video name: " + super.getName());
        System.out.println("duration: " + get_duration());
        System.out.println("dimension: " + get_dimension());
    }
    
}
