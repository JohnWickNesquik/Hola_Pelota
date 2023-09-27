#include <iostream>
#include <Box2D\Box2D.h>

int main() {



    //Gravity
    b2Vec2 gravity( 0.f , -10.f );

    //World
    b2World world( gravity );


    //We define a body and set the position
    b2BodyDef bodyDefDynamic;
    bodyDefDynamic.type = b2_dynamicBody;
    bodyDefDynamic.position.Set(10.0f, -10.f);

    //Body creation
    b2Body *dynamicBody = world.CreateBody(&bodyDefDynamic);

    //We give a circle shape to it
    b2CircleShape circle;
    circle.m_p.Set(20.0f, 20.0f);
    circle.m_radius = 1.0f;

    //Fixture
    b2FixtureDef fixtureDefDynamic;
    fixtureDefDynamic.shape = &circle;
    fixtureDefDynamic.friction= 0.0f;

    //Creating the fixture
    dynamicBody->CreateFixture(&fixtureDefDynamic);

    float timeStep = 1.0f / 60.0f;
    // Convertimos km/hr a m/s
    int32 velocityIterations = 5.5f;
    int32 positionIterations = 3;

    for (int32 i = 0; i < 5.5; ++i)
    {
        world.Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = dynamicBody->GetPosition();
        float angle = 75.0f;
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }





}
