public class Image extends Entry implements Non_playable, Visual {

    private int dimension;
    private double size;

    public Image(String n, int dim, double s)  /* constructor */
    {
        super(n);  /* calls entry class*/
        dimension = dim;
        size = s;
    }

    public int get_dimension()
    {
        return dimension;  /* returns dimension */
    }

    public double get_size()
    {
        return size;  /* returns size */
    }

    @Override
    public void info()  /* writes object informations */
    {
        System.out.println("Image name: " + super.getName());
        System.out.println("dimension: " + get_dimension());
        System.out.println("size: " + get_size());
    }

}
