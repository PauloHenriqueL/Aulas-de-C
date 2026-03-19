#include <stdio.h>
#include <math.h>


int main(){

    printf("Questao 1: \n");
    
    printf("\n");
    printf("a) 3 + 4 = %d\n", (3 + 4));
    printf("b) 7 / 4 = %.2lf \n", (7.0 / 4.0));
    printf("c) 3^2 = %.2lf \n", pow(3, 2));
    printf("d) 5.3 * 2.1 = %.3lf \n", (5.3 * 2.1));
    printf("e) 2 * 5 - 2 = %d\n", (2 * 5 -2));
    printf("f) 2 + 2 * 5 = %d\n", (2 + 2 * 5));
    printf("g) (2 + 5) * 3 = %d\n", ((2 + 5) * 3));
    printf("h) sin(3.141502) = %.6lf\n", sin(3.141502));
    printf("i) sqrt(5) = %.3lf\n", sqrt(5));
    printf("j) 1 + 2 + 3 = %d\n", (1 + 2 + 3));
    printf("k) 1 * 2 * 3 = %d\n", (1 * 2 * 3));
    printf("l) (1 + 2 + 3) / 3.0 = %.2lf\n", ((1 + 2 + 3) / 3.0));
    printf("m) (2 + 4) * (3 - 1) = %d\n", ((2 + 4) * (3 - 1)));
    printf("n) (9 / 3) + (3 * 2) = %d\n", ((9/3) + (3 * 2)));
    printf("o) sin(4.5) + cos(3.7) = %.3lf\n", (sin(4.5) + cos(3.7)));
    printf("p) log(2.3) - log(3.1) = %.3lf\n", (log(2.3) - log(3.1)));
    printf("q) log(7) + log(7) * log(7) - cos(log(7)) = %.3lf\n", (log(7) + log(7) * log(7) - cos(log(7))));
    printf("r) (10.3 + 8.4)/50.3 - (10.3 + 8.4) = %.3lf\n", ((10.3 + 8.4)/50.3 - (10.3 + 8.4)));
    printf("s) (cos(0.8) + sin(0.8)) * (cos(0.8) - sin(0.8))  = %.3lf\n", ((cos(0.8) + sin(0.8)) * (cos(0.8) - sin(0.8))));
    printf("\n");
   
    printf("Questao 2: \n");

    float a, b, c, d;
    printf("Digite o valor de a: ");
    scanf("%f", &a);
    printf("Digite o valor de b: ");
    scanf("%f", &b);
    printf("Digite o valor de c: ");
    scanf("%f", &c);
    printf("Digite o valor de d: ");
    scanf("%f", &d);

    printf("a) a + b = %f\n", (a + b));
    printf("b) a/c = %f\n", (a / c));
    printf("c) a^2 = %f\n", pow(a,2));
    printf("d) b * c = %f\n", (b * c));
    printf("e) a * b - c = %f\n", (a * b - c));
    printf("f) a + b * c = %f\n", (a + b * c));
    printf("g) (a + b) * c = %f\n", (a + b) * c);
    printf("h) sin(a) = %f\n", sin(a));
    printf("i) sqrt(b) = %f\n", sqrt(b));
    printf("j) a + b + c = %f\n", (a + b + c));
    printf("k) a * b * c = %f\n", (a * b * c));
    printf("l) (a + b + c)/d = %f\n", ((a + b + c)/d));
    printf("m) (a + b) * (a - d) = %f\n", (a + b) * (a - d));
    printf("n) (b / c) + (a * d) = %f\n", (b / c) + (a * d));
    printf("o) sin(b) + cos(c) = %f\n", sin(b) + cos(c));
    printf("p) log(a) - log(c) = %f\n", log(a) - log(c));
    printf("q) log(a) + (log(b) * log(d) - cos(log(c))) = %f\n", (log(a) + (log(b) * log(d) - cos(log(c)))));
    printf("r) (b + a)/c - (d + a) = %f\n", ((b + a)/c - (d + a)));
    printf("s) (cos(d) + sin(c)) * (cos(b) - sin(a)) = %f\n", ((cos(d) + sin(c)) * (cos(b) - sin(a))));

    printf("\n");
    printf("Questao 3");
    printf("\n");
    printf("Digite o valor de a: ");
    scanf("%f", &a);
    printf("Digite o valor de b: ");
    scanf("%f", &b);
    printf("Digite o valor de c: ");
    scanf("%f", &c);
    printf("a)Media de a, b e c. %f \n", (a + b + c)/3.0);
    printf("b)Media ponderada de peso a 3, b 4 e c 5. %f\n", (a*3 + b*4 + c*5)/12.0);
    printf("c)Perimetro de um circulo de raio a. %f\n", (2.0 * 3.14159 * a));
    printf("d)Area de um circulo de raio a. %f\n", (3.14159 * pow(a, 2.0)));
    printf("e)Area de um triangulo de base b e altura c. %f\n", (b * c)/2.0);
    printf("f)Hipotenusa cujos lados conhecidos sao b e c. %f\n", hypot(b, c));
    
    float delta = pow(b, 2) -4 * a * c;
    float x1 = (-b + sqrt(delta)) / (2 * a);
    float x2 = (-b - sqrt(delta)) / (2 * a);

    printf("g)Raizes da equacao a.x2 + b.x + c. x1 = %f, x2 = %f  \n", x1, x2);
    

    return 0;
}