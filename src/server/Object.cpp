/*
** EPITECH PROJECT, 2020
** Object.cpp
** File description:
** Object
*/

#include "Object.hpp"

Object::Object(object_e type, size_t id,
               std::string path, sf::Vector2f pos, sf::Vector2i size, sf::Vector2f move,
               float speed, size_t time, std::vector<size_t> anim, std::vector<size_t> event)
{
    _id = id;
    _type = type;
    _path = path;
    _size = size;
    _pos = pos;
    _time = time;
    _speed = speed;
    _move = move;
    _clock_anim.restart();
    _all_events = event;
    _anim_state = sf::Vector2i(0, 0);
    for (size_t i = 0; i < _all_events.size(); i++)
        _events[_all_events.at(i)] = false;
    
    if (anim.size() == 3) {
        _state = anim.at(0);
        _nb_state = anim.at(1);
        _nb_frame = anim.at(2);
    } else {
        _nb_frame = 0;
        _state = 0;
    }
}

void Object::collide(sf::Vector2i size)
{
    if (_pos.x + _move.x * _speed + _size.x >= size.x || _pos.x + _move.x * _speed < 0)
        _move.x = 0;
    if (_pos.y + _move.y * _speed + _size.y >= size.y || _pos.y + _move.y * _speed < 0)
        _move.y = 0;
}


void Object::moveEntity()
{
    _pos.x += _move.x * _speed;
    _pos.y += _move.y * _speed;
}

sf::Vector2f Object::getMove() const
{
    return _move;
}

object_e Object::getType() const
{
    return _type;
}

void Object::setMove(sf::Vector2f move)
{
    _move = move;
}


std::map<size_t, bool> Object::getMapEvents() const
{
    return _events;
}


std::vector<size_t> Object::getEvents() const
{
    return _all_events;
}
void Object::setEvent(size_t id, bool state)
{
    _events[id] = state;
}

Object::~Object()
{

}

void Object::setPos(sf::Vector2f pos)
{
    _pos = pos;
}

void Object::setSize(sf::Vector2i size)
{
    _size = size;
}

sf::Vector2f Object::getPos() const
{
    return _pos;
}

sf::Vector2i Object::getSize() const
{
    return _size;
}

std::string Object::getPath() const
{
    return _path;
}


size_t Object::getState() const
{
    return _state;
}
size_t Object::getNbFrame() const
{
    return _nb_frame;
}

sf::Vector2i Object::getStateAnim() const
{
    return _anim_state;
}

void Object::clockAnimRestart()
{
    _clock_anim.restart();
}


sf::Clock Object::getClockAnim() const
{
    return _clock_anim;
}

void Object::setStateAnim(sf::Vector2i anim_state)
{
    _anim_state = anim_state;
}

size_t Object::getTime() const
{
    return _time;
}
