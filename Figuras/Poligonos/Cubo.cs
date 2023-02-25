// Nombre del paquete
namespace Figuras.Poligonos;

public class Cubo : IPoligono
{
    private double _lado;
    //atributo en privado es _

    //contructor
    public Cubo(double lado)
    {
        _lado = lado;
    }

    // Se agregan el get y set en una propiedad
    public double Lado
    {
        get => _lado;
        set 
        {
            if(value <= 0)
                throw new ArgumentException("Lado debe ser mayor a cero");

            _lado = value;
        }
    }

    // Metodos 
    public double Area()
    {
        return _lado * _lado;
    }

    public double Perimetro() => _lado * 4;

    // Sobreescritura de metodsos
    public override string ToString()
    {
        return $"Cubo de Lado = {_lado}";
    }
}