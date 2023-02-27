import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calculadora extends JFrame implements ActionListener {
    private JTextField textFieldNumero1;
    private JTextField textFieldNumero2;
    private JButton botonSuma;
    private JButton botonResta;
    private JButton botonMultiplicacion;
    private JButton botonDivision;
    private JLabel labelResultado;

    public Calculadora() {
        super("Calculadora");

        // Configuración de la ventana
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(5, 2));

        // Creación de los componentes de la interfaz
        JLabel labelNumero1 = new JLabel("Número 1:");
        JLabel labelNumero2 = new JLabel("Número 2:");
        textFieldNumero1 = new JTextField();
        textFieldNumero2 = new JTextField();
        botonSuma = new JButton("+");
        botonResta = new JButton("-");
        botonMultiplicacion = new JButton("*");
        botonDivision = new JButton("/");
        labelResultado = new JLabel();

        // Agregamos los componentes a la ventana
        add(labelNumero1);
        add(textFieldNumero1);
        add(labelNumero2);
        add(textFieldNumero2);
        add(botonSuma);
        add(botonResta);
        add(botonMultiplicacion);
        add(botonDivision);
        add(new JLabel("Resultado:"));
        add(labelResultado);

        // Agregamos listeners a los botones para manejar las acciones
        botonSuma.addActionListener(this);
        botonResta.addActionListener(this);
        botonMultiplicacion.addActionListener(this);
        botonDivision.addActionListener(this);

        // Hacemos visible la ventana
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        double numero1 = Double.parseDouble(textFieldNumero1.getText());
        double numero2 = Double.parseDouble(textFieldNumero2.getText());
        String operacion = e.getActionCommand();
        double resultado = 0.0;

        switch (operacion) {
            case "+":
                resultado = numero1 + numero2;
                break;
            case "-":
                resultado = numero1 - numero2;
                break;
            case "*":
                resultado = numero1 * numero2;
                break;
            case "/":
                resultado = numero1 / numero2;
                break;
            default:
                break;
        }

        labelResultado.setText(Double.toString(resultado));
    }

    public static void main(String[] args) {
        new Calculadora();
    }
}
