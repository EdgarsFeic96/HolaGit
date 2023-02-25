//paquete 
namespace Figuras.Poligonos;

public class Circulo : IPoligono
{
    private double _radio;

    public Circulo(double radio)
    {
        _radio = radio;
    }

    public double Radio
    {
        get => _radio;
        set
    {
        if(value <=0) 
            throw new ArgumentException("Lado debe ser mayor a cero");

        _radio = value;

    }
}
    public double Area()
    {
        return Math.PI * Math.Pow(_radio, 2);
    }

    public double Perimetro()
    {
        return 2 * Math.PI * _radio;
    }

    public override string ToString()
    {
        return $"Circulo de radio: {_radio}";
    }
}