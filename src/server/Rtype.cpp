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
