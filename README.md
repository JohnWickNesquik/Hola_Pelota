# Hola_Pelota

#Objetivo
Simulacion de Lanzamiento de Pelota en la cual una pelota de 1m de radio sin densidad es lanzada a un angulo de 75° con una Velocidad de 20 Km/h.
Se hizo tomando en cuenta la conversion de km/h a m/s para tener la medida ideal.

#Link proyecto
Proyecto e informacion en: https://github.com/JohnWickNesquik/Hola_Pelota.git

# Concepto de Vector
Es una representacion grafica de una fuerza fisica, se representa como un movimiento.

#Calcular componentes de un vector
Para esto se necesita saber sus caracteristicas, despues se puede descomponer en el eje X y Y. Vx= Vcos(teta), Vy = Vsen(teta)
luego se suman los vectores en x y en Y, despues se aplica la formula 0= Tan-1(EVy/EVx) y Vr= sqrt(VX^2+Vy^2)

#Conversion de unidades
Se puede hacer una regla de 3, por ejemplo para convertir 72 km/h a m/s es:

72km/h (5/18)= 20 m/s, asi mismo de 20m/s a km/h es 20 m/s (18/5)= 72 km/h

##CODIGO

#include <iostream>
#include <Box2D\Box2D.h>

int main() {



    //Se define la gravedad, en la tierra.
    b2Vec2 gravity( 0.f , -10.f );

    //Aqui definimos el mundo con la gravedad
    b2World world( gravity );


    //Se define el cuerpo y su posicion
    b2BodyDef bodyDefDynamic;
    bodyDefDynamic.type = b2_dynamicBody;
    bodyDefDynamic.position.Set(10.0f, -10.f);

    //Se crea el cuerpo en el mundo
    b2Body *dynamicBody = world.CreateBody(&bodyDefDynamic);

    //Se le da una forma de circulo y se posiciona junto a su radio.
    b2CircleShape circle;
    circle.m_p.Set(20.0f, 20.0f);
    circle.m_radius = 1.0f;

    //Fixture donde se le da la forma y friccion
    b2FixtureDef fixtureDefDynamic;
    fixtureDefDynamic.shape = &circle;
    fixtureDefDynamic.friction= 0.0f;

    /Aqui se crea la fixture
    dynamicBody->CreateFixture(&fixtureDefDynamic);

    float timeStep = 1.0f / 60.0f;
    // Convertimos km/hr a m/s
    int32 velocityIterations = 5.5f;
    int32 positionIterations = 3;

    //Aqui el for actualizara posicion por posicion el movimiento

    for (int32 i = 0; i < 5.5; ++i)
    {
        world.Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = dynamicBody->GetPosition();
        float angle = 75.0f;
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }





}

## La actividad nos introdujo aun mas a saber analizar el codigo y poder modificar parametros, body, formas y fisicas de acuerdo a la simulacion que queremos correr.
