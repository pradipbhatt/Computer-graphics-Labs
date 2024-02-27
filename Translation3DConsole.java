import java.util.Scanner;

class Point3D {
    double x;
    double y;
    double z;

    public Point3D(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public void translate(double dx, double dy, double dz) {
        this.x += dx;
        this.y += dy;
        this.z += dz;
    }

    @Override
    public String toString() {
        return "(" + x + ", " + y + ", " + z + ")";
    }
}

public class Translation3DConsole {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter initial 3D point coordinates:");
        System.out.print("x: ");
        double initialX = scanner.nextDouble();
        System.out.print("y: ");
        double initialY = scanner.nextDouble();
        System.out.print("z: ");
        double initialZ = scanner.nextDouble();

        Point3D point = new Point3D(initialX, initialY, initialZ);

        System.out.println("Initial point: " + point);

        System.out.println("Enter translation distances in 3D (dx, dy, dz):");
        System.out.print("dx: ");
        double dx = scanner.nextDouble();
        System.out.print("dy: ");
        double dy = scanner.nextDouble();
        System.out.print("dz: ");
        double dz = scanner.nextDouble();

        // Perform translation
        point.translate(dx, dy, dz);

        System.out.println("After translation: " + point);

        scanner.close();
    }
}
