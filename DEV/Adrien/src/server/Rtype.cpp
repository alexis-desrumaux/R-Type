/*
** EPITECH PROJECT, 2020
** Rtype.cpp
** File description:
** Rtype
*/

#include "Rtype.hpp"

typedef struct info_s
{
    float               speed;
    std::string         path;
    sf::Vector2f        pos;
    sf::Vector2i        size;
    sf::Vector2f        move;
    size_t              time;
    size_t              anim_size;
    size_t              event_size;
}info_t;

size_t   info_anim[][3] = {
    {},
    {0, 0, 8},
    {0, 0, 4}
};
size_t   info_event[][5] = {
    {},
    {0, 1, 2, 3, 4},
    {}
};

Rtype::Rtype(size_t size_x, size_t size_y, std::string name)
{
    _object_id[BACKGROUND] = 0;
    _object_id[PLAYER] = 1;
    _object_id[BULLET] = 2;
    addEntity(BACKGROUND);
    addEntity(BACKGROUND);
    addEntity(PLAYER);
    addEntity(BULLET);
    _window_size_x = size_x;
    _window_size_y = size_y;
    _window_name = name;
}

Rtype::~Rtype() {}

size_t Rtype::newId()
{
    size_t max = 0;
    for (size_t i = 0; i < _all_entity.size(); i++)
        if (max < _all_entity.at(i))
            max = _all_entity.at(i);
    max++;
    return max;
}

size_t Rtype::addEntity(object_e obj)
{
    size_t id_obj = _object_id[obj];
    size_t id = newId();
    std::vector<size_t> ids;

    if (_all_id.find(obj) == _all_id.end())
        ids.push_back(id);
    else {
        ids = _all_id[obj];
        ids.push_back(id);
    }
    _all_id[obj] = ids;

    _create_entity.push_back(id);
    _all_entity.push_back(id);
    _display_order.push_back(id);

    std::vector<size_t> anim (info_anim[id_obj], info_anim[id_obj] + info[id_obj].anim_size);
    std::vector<size_t> event (info_event[id_obj], info_event[id_obj] + info[id_obj].event_size);

    _entity[id] = new Object(
        obj, id,
        info[id_obj].path,
        info[id_obj].pos,
        info[id_obj].size,
        info[id_obj].move,
        info[id_obj].speed,
        info[id_obj].time,
        anim,
        event
        );
    return id;
}

void Rtype::removeEntity(size_t id, object_e lol)
{
    size_t index = 0;

    for (; index < _all_entity.size() && id != _all_entity.at(index); index++);
    _all_entity.erase(_all_entity.begin() + index);

    std::vector<size_t> ids = _all_id[lol];
    index = 0;
    for (; index < ids.size() && id != ids.at(index); index++);
    ids.erase(ids.begin() + index);
    _all_id[lol] = ids;
    _delete_entity.push_back(id);
}

size_t Rtype::getWindowSizeX() const
{
    return _window_size_x;
}

size_t Rtype::getWindowSizeY() const
{
    return _window_size_y;
}

std::string Rtype::getWindowName() const
{
    return _window_name;
}

std::vector<size_t> Rtype::getCreateEntity() const
{
    return _create_entity;
}

std::vector<size_t> Rtype::getAllEntity() const
{
    return _all_entity;
}

std::map<size_t, Object *> Rtype::getEntity() const
{
    return _entity;
}

std::vector<size_t> Rtype::getDeleteEntity() const
{
    return _delete_entity;
}

void Rtype::updateBackGround()
{
    std::vector<size_t> ids = _all_id[BACKGROUND];

    size_t id_first = ids.at(0);
    size_t id_second = ids.at(1);

    if (_entity[id_first]->getPos().x > _entity[id_second]->getPos().x) {
        id_first = ids.at(1);
        id_second = ids.at(0);
    }
    _entity[id_first]->moveEntity();
    _entity[id_second]->setPos(
        sf::Vector2f(_entity[id_first]->getPos().x + _entity[id_first]->getSize().x,
                     _entity[id_second]->getPos().y));
    if (_entity[id_first]->getPos().x + _entity[id_first]->getSize().x <= (float)0)
        _entity[id_first]->setPos(sf::Vector2f(_entity[id_second]->getPos().x + _entity[id_second]->getSize().x - 1, 0));
}

void    Rtype::updatePlayer()
{

    std::vector<size_t> ids = _all_id[PLAYER];

    for (size_t i = 0; i < ids.size(); i++) {
        sf::Vector2f move(0, 0);

        if (_entity[ids.at(i)]->getMapEvents()[0])
            move.x = 1;;
        if (_entity[ids.at(i)]->getMapEvents()[1])
            move.x += -1;
        if (_entity[ids.at(i)]->getMapEvents()[2])
            move.y = 1;
        if (_entity[ids.at(i)]->getMapEvents()[3])
            move.y += -1;
        sf::Time t = _clock_bullet.getElapsedTime();
        size_t milli = t.asMilliseconds();
        if (milli > 500) {
            if (_entity[ids.at(i)]->getMapEvents()[4]) {
                _clock_bullet.restart();
                size_t id_bullet = addEntity(BULLET);
                _entity[id_bullet]->setPos(sf::Vector2f(_entity[ids.at(i)]->getPos().x - 20 + _entity[ids.at(i)]->getSize().x, _entity[ids.at(i)]->getPos().y + 50));
            }
        }
        _entity[ids.at(i)]->setMove(move);
        _entity[ids.at(i)]->collide(sf::Vector2i(1024, 720));
        _entity[ids.at(i)]->moveEntity();
    }
}

void    Rtype::updateBullet()
{
    std::vector<size_t> ids = _all_id[BULLET];
    for (size_t i = 0; i < ids.size(); i++) {
        sf::Time t = _entity[ids.at(i)]->getClockAnim().getElapsedTime();
        size_t milli = t.asMilliseconds();
        // std::cout << _entity[ids.at(i)]->getNbFrame() <<  " " << _entity[ids.at(i)]->getStateAnim().x << " " << milli <<"\n";
        if (milli > _entity[ids.at(i)]->getTime()) {
            _entity[ids.at(i)]->clockAnimRestart();
            if (_entity[ids.at(i)]->getStateAnim().x == _entity[ids.at(i)]->getNbFrame() - 1) {
                _entity[ids.at(i)]->setStateAnim(sf::Vector2i(
                                                     0,
                                                     _entity[ids.at(i)]->getStateAnim().y));
            } else {
                _entity[ids.at(i)]->setStateAnim(sf::Vector2i(
                                                     _entity[ids.at(i)]->getStateAnim().x + 1,
                                                     _entity[ids.at(i)]->getStateAnim().y));
            }
        }
        _entity[ids.at(i)]->moveEntity();
        if (_entity[ids.at(i)]->getPos().x > _window_size_x)
            removeEntity(ids.at(i), _entity[ids.at(i)]->getType());
    }
}

void Rtype::updateRtype()
{
    _delete_entity.erase(_delete_entity.begin(), _delete_entity.end());
    _create_entity.erase(_create_entity.begin(), _create_entity.end());
    updateBackGround();
    updatePlayer();
    updateBullet();
}

std::string Rtype::getMessage()
{
    std::string message("");

    for (size_t i = 0; i < _all_entity.size(); i++) {
        if (i != 0)
            message += "\n";
        message = message + std::to_string(_object_id[_entity[_all_entity.at(i)]->getType()]) + " ";
        message = message + std::to_string(_entity[_all_entity.at(i)]->getPos().x) + " ";
        message = message + std::to_string(_entity[_all_entity.at(i)]->getPos().y) + " ";
        message = message + std::to_string(_entity[_all_entity.at(i)]->getStateAnim().x) + " ";
        message = message + std::to_string(_entity[_all_entity.at(i)]->getStateAnim().y);
    }
    return message;
}
