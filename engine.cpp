#include "engine.h"

Engine &Engine::getInstance()
{
    static Engine instance;
    return instance;
}

Engine::Engine() : QObject(0)
{

}
