using Figuras.Poligonos;
//Se importa un paquete

double ladoCubo;

#nullable disable

Console.Write("Ingresa el lado del cubo: ");
ladoCubo = double.Parse(Console.ReadLine());

var miCubo = new Cubo(ladoCubo);

//Se llama metodo ToString
Console.WriteLine(miCubo);
//Se llama metodos de la clase
Console.WriteLine($"El area es: {miCubo.Area()}");
Console.WriteLine($"EL perimetro es: {miCubo.Perimetro()}");

var miCirculo = new Circulo(6);
Console.WriteLine(miCirculo);
//Se llama metodos de la clase
Console.WriteLine($"El area del circulo es: {miCirculo.Area()}");
Console.WriteLine($"EL perimetro de circulo es: {miCirculo.Perimetro()}");

//Lista de poligonos a partir de la interfaz
Console.WriteLine("\nListado de poligonos\n");
List<IPoligono> poligonos = new();
poligonos.Add(miCirculo);
poligonos.Add(miCubo);
poligonos.ForEach(p => Console.WriteLine(p));