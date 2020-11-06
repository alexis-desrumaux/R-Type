/*
** EPITECH PROJECT, 2020
** Rtype.hpp
** File description:
** Rtype
*/

#ifndef _RTYPE_HPP_
#define _RTYPE_HPP_

#include "IGame.hpp"

class Rtype : public IGame
{
public:
    Rtype(size_t x, size_t, std::string);
    ~Rtype();
    size_t getWindowSizeX() const;
    size_t getWindowSizeY() const;
    std::string getWindowName() const;
    std::string getMessage();
    std::vector<size_t> getCreateEntity() const;
    std::vector<size_t> getDeleteEntity() const;
    std::vector<size_t> getAllEntity() const;
    std::map<size_t, Object *> getEntity() const;
    void updateRtype();
    size_t addEntity(object_e obj);
    void removeEntity(size_t id, object_e type);
    size_t newId();
    void updateBackGround();
    void updatePlayer();
    void updateBullet();

private:
    std::map<object_e, size_t> _object_id;
    std::map<object_e, std::vector<size_t>> _all_id;
    std::vector<size_t> _create_entity;
    std::vector<size_t> _all_entity;
    std::vector<size_t> _display_order;
    std::vector<size_t> _delete_entity;
    std::map<size_t, Object *> _entity;
    size_t _window_size_x;
    size_t _window_size_y;
    std::string _window_name;
    sf::Clock _clock_bullet;
};

#endif