public class Text extends Entry implements Non_visual, Non_playable {

    private double size;

    public Text(String n, double s)  /* constructor */
    {
        super(n);  /* calls entry class*/
        size = s;
    }

    public double get_size()
    {
        return size;  /* returns size */
    }

    @Override
    public void info()  /* writes object informations */
    {
        System.out.println("Text name: " + super.getName());
        System.out.println("size: " + get_size());
    }
}
