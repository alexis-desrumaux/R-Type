/*
** EPITECH PROJECT, 2020
** Object.hpp
** File description:
** Object
*/

#ifndef _OBJECT_HPP_
# define _OBJECT_HPP_

#include <iostream>
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

typedef enum test {
    BACKGROUND,
    PLAYER,
    BULLET
}object_e;

class IObject
{
public:
    ~IObject() {};

    virtual void setPos(sf::Vector2f pos) = 0;
    virtual void setSize(sf::Vector2i size) = 0;
    virtual void setMove(sf::Vector2f move) = 0;
    virtual void setEvent(size_t id, bool event) = 0;

    virtual void moveEntity() = 0;
    virtual void collide(sf::Vector2i border) = 0;

    virtual sf::Vector2f getMove() const = 0;
    virtual sf::Vector2f getPos() const = 0;
    virtual sf::Vector2i getSize() const = 0;
    virtual std::string getPath() const = 0;
    virtual size_t getState() const = 0;
    virtual size_t getNbFrame() const = 0;
    virtual std::vector<size_t> getEvents() const = 0;
    virtual std::map<size_t, bool> getMapEvents() const = 0;
};

class Object : public IObject
{
public:
    Object(object_e type, size_t id,
           std::string path, sf::Vector2f pos, sf::Vector2i size, sf::Vector2f move,
           float speed, size_t time, std::vector<size_t> anim, std::vector<size_t> event);
    ~Object();

    void setPos(sf::Vector2f);
    void setSize(sf::Vector2i);
    void setMove(sf::Vector2f move);
    void setStateAnim(sf::Vector2i anim_state);
    void setEvent(size_t, bool);

    void clockAnimRestart();
    void moveEntity();
    void collide(sf::Vector2i);

    size_t getTime() const;
    sf::Vector2f getMove() const;
    sf::Vector2f getPos() const;
    sf::Vector2i getSize() const;
    sf::Vector2i getStateAnim() const;
    sf::Clock getClockAnim() const;
    std::string getPath() const;
    object_e getType() const;
    size_t getState() const;
    size_t getNbFrame() const;
    std::vector<size_t> getEvents() const;
    std::map<size_t, bool> getMapEvents() const;
private:
    std::vector<size_t> _all_events;
    std::map<size_t, bool> _events;
    std::string _path;
    sf::Vector2f _pos;
    sf::Vector2f _move;
    sf::Vector2i _size;
    sf::Clock _clock_anim;
    sf::Vector2i _anim_state;
    size_t _time;
    float _speed;
    size_t _state;
    size_t _nb_state;
    size_t _nb_frame;
    object_e _type;
    size_t _id;
};

#endif