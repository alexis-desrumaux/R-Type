/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Components
*/

#include "../include/Components.hpp"

bool isOnChangeExist(std::vector<int> *onChange, int def)
{
    bool check = false;

    if (onChange->empty())
        return false;
    else {
        for (size_t i = 0; i != onChange->size(); i += 1) {
            if (onChange->at(i) == def)
                check = true;
        }
        if (check == false)
            return false;
    }
    return true;
}

/*-------------------------AUDIO-----------------------*/

std::string Component::Audio::serialize(void)
{

    Parser parser = Parser();

    parser.addKey("document", "data");
    parser.addKey("type", "AUDIO");
    parser.addKey("name", this->componentName);
    parser.addKey("display", this->display ? "true" : "false");
    parser.addKey("path", this->path);
    if (this->audioState == AudioState::AudioState::PAUSE)
        parser.addKey("audioState", "PAUSE");
    if (this->audioState == AudioState::AudioState::PLAY)
        parser.addKey("audioState", "PLAY");
    if (this->audioState == AudioState::AudioState::RELOAD)
        parser.addKey("audioState", "RELOAD");
    if (this->audioState == AudioState::AudioState::STOP)
        parser.addKey("audioState", "STOP");
    parser.addKey("loop", this->loop ? "true" : "false");
    return parser.stringify();
}

void Component::Audio::setLoop(bool state)
{
    this->loop = state;
}

bool Component::Audio::isLoop(void)
{
    return this->loop;
}

void Component::Audio::setAudioState(AudioState::AudioState state)
{
    this->audioState = state;
}

Component::AudioState::AudioState Component::Audio::getAudioState()
{
    return this->audioState;
}

void Component::Audio::setAudioPath(std::string path)
{
    this->path = path;
}

std::string Component::Audio::getAudioPath()
{
    return this->path;
}

Component::Audio::Audio(std::string data)
{
    Parser parser = Parser(data);
    Parser f;

    if (parser.isKeyExist("document") == false)
        return;
    if (parser.getValueOfKey("document") != "data")
        return;
    if (parser.getValueOfKey("type") != "AUDIO")
        return;
    this->type = listComponent::AUDIO;
    this->componentName = parser.getValueOfKey("name");
    this->display = parser.getValueOfKey("display") == "true" ? 1 : 0;
    this->path = parser.getValueOfKey("path");
    std::string audioState = parser.getValueOfKey("audioState");
    if (audioState == "PAUSE")
        this->audioState = Component::AudioState::PAUSE;
    if (audioState == "PLAY")
        this->audioState = Component::AudioState::PLAY;
    if (audioState == "RELOAD")
        this->audioState = Component::AudioState::RELOAD;
    if (audioState == "STOP")
        this->audioState = Component::AudioState::STOP;
    this->loop = parser.getValueOfKey("loop") == "true" ? 1 : 0;
}

Component::Audio::Audio(std::string componentName, std::string path, AudioState::AudioState state, bool loop)
{
    this->componentName = componentName;
    this->type = listComponent::AUDIO;
    this->display = true;
    this->path = path;
    this->audioState = state;
    this->loop = loop;
}

Component::Audio::~Audio()
{
    std::cout << "DELETED " << this->componentName << std::endl;
}

/*-------------------------SPRITE-----------------------*/

std::string Component::Sprite::serialize(void)
{
    Parser parser;
    Parser f;

    parser.addKey("document", "data");
    parser.addKey("type", "SPRITE");
    parser.addKey("name", this->componentName);
    parser.addKey("display", this->display ? "true" : "false");
    parser.addKey("path", this->path);
    f.addKey("x", std::to_string(this->pos.first));
    f.addKey("y", std::to_string(this->pos.second));
    parser.addKey("pos", f.stringify());
    f.clear();
    f.addKey("scaleX", std::to_string(this->scale.first));
    f.addKey("scaleY", std::to_string(this->scale.second));
    parser.addKey("scale", f.stringify());
    f.clear();
    f.addKey("x", std::to_string(this->rect.first.first));
    f.addKey("width", std::to_string(this->rect.first.second));
    f.addKey("y", std::to_string(this->rect.second.first));
    f.addKey("height", std::to_string(this->rect.second.second));
    parser.addKey("rect", f.stringify());
    f.clear();
    return parser.stringify();
}

void Component::Sprite::setRect(int x, int size_x, int y, int size_y)
{
    this->rect.first.first = x;
    this->rect.first.second = size_x;
    this->rect.second.first = y;
    this->rect.second.second = size_y;
}

std::pair<std::pair<int, int>, std::pair<int, int>> Component::Sprite::getRect()
{
    return this->rect;
}

void Component::Sprite::setScale(std::pair<float, float> scale)
{
    this->scale = scale;
}

std::pair<float, float> Component::Sprite::getScale()
{
    return this->scale;
}

void Component::Sprite::setPosition(std::pair<float, float> pos)
{
    this->pos = pos;
}

std::pair<float, float> Component::Sprite::getPosition()
{
    return this->pos;
}

void Component::Sprite::setSpritePath(std::string path)
{
    this->path = path;
}

std::string Component::Sprite::getSpritePath(void)
{
    return this->path;
}

Component::Sprite::Sprite(std::string data)
{
    Parser parser = Parser(data);
    Parser f;

    if (parser.isKeyExist("document") == false)
        return;
    if (parser.getValueOfKey("document") != "data")
        return;
    if (parser.getValueOfKey("type") != "SPRITE")
        return;
    this->type = listComponent::SPRITE;
    this->componentName = parser.getValueOfKey("name");
    this->display = parser.getValueOfKey("display") == "true" ? 1 : 0;
    this->path = parser.getValueOfKey("path");
    f.set(parser.getValueOfKey("pos"));
    this->pos.first = std::stof(f.getValueOfKey("x"));
    this->pos.second = std::stof(f.getValueOfKey("y"));
    f.set(parser.getValueOfKey("scale"));
    this->scale.first = std::stof(f.getValueOfKey("scaleX"));
    this->scale.second = std::stof(f.getValueOfKey("scaleY"));
    f.set(parser.getValueOfKey("rect"));
    this->rect.first.first = std::stoi(f.getValueOfKey("x"));
    this->rect.first.second = std::stoi(f.getValueOfKey("width"));
    this->rect.second.first = std::stoi(f.getValueOfKey("y"));
    this->rect.second.second = std::stoi(f.getValueOfKey("height"));
}

Component::Sprite::Sprite(std::string componentName, std::string path, std::pair<float, float> pos, std::pair<float, float> scale)
{
    this->componentName = componentName;
    this->type = listComponent::SPRITE;
    this->display = true;
    this->path = path;
    this->pos = pos;
    this->scale = scale;
    this->rect = std::pair<std::pair<int, int>,
    std::pair<int, int>>({-1, -1}, {-1, -1});
}

Component::Sprite::~Sprite()
{
    std::cout << "DELETED " << this->componentName << std::endl;
}

/*-------------------------TEXT-----------------------*/

std::string Component::Text::serialize(void)
{
    Parser parser;
    Parser f;

    parser.addKey("document", "data");
    parser.addKey("type", "TEXT");
    parser.addKey("name", this->componentName);
    parser.addKey("display", this->display ? "true" : "false");
    if (this->color == Component::Color::Color::Black)
        parser.addKey("color", "BLACK");
    if (this->color == Component::Color::Color::Blue)
        parser.addKey("color", "BLUE");
    if (this->color == Component::Color::Color::Green)
        parser.addKey("color", "GREEN");
    if (this->color == Component::Color::Color::Red)
        parser.addKey("color", "RED");
    if (this->color == Component::Color::Color::White)
        parser.addKey("color", "WHITE");
    parser.addKey("str", this->str);
    parser.addKey("fontPath", this->fontPath);
    parser.addKey("size", std::to_string(this->size));
    f.addKey("x", std::to_string(this->pos.first));
    f.addKey("y", std::to_string(this->pos.second));
    parser.addKey("pos", f.stringify());
    return parser.stringify();
}

void Component::Text::setPosXY(std::pair<float, float> pos)
{
    this->pos = pos;
}

std::pair<float, float> Component::Text::getPosXY(void)
{
    return this->pos;
}

void Component::Text::setFontSize(int size)
{
    this->size = size;
}

int Component::Text::getFontSize(void)
{
    return this->size;
}

void Component::Text::setFontPath(std::string path)
{
    this->fontPath = path;
}

std::string Component::Text::getFontPath(void)
{
    return this->fontPath;
}

void Component::Text::setText(std::string str)
{
    this->str = str;
}

std::string Component::Text::getText(void)
{
    return this->str;
}

void Component::Text::setColor(Color::Color color)
{
    this->color = color;
}

Component::Color::Color Component::Text::getColor(void)
{
    return this->color;
}

Component::Text::Text(std::string data)
{

    Parser parser = Parser(data);
    Parser f;

    if (parser.isKeyExist("document") == false)
        return;
    if (parser.getValueOfKey("document") != "data")
        return;
    if (parser.getValueOfKey("type") != "TEXT")
        return;
    this->type = listComponent::TEXT;
    this->componentName = parser.getValueOfKey("name");
    this->display = parser.getValueOfKey("display") == "true" ? 1 : 0;
    std::string color = parser.getValueOfKey("color");
    if (color == "BLACK")
        this->color = Component::Color::Color::Black;
    if (color == "BLUE")
        this->color = Component::Color::Color::Blue;
    if (color == "GREEN")
        this->color = Component::Color::Color::Green;
    if (color == "RED")
        this->color = Component::Color::Color::Red;
    if (color == "WHITE")
        this->color = Component::Color::Color::White;
    this->str = parser.getValueOfKey("str");
    this->fontPath = parser.getValueOfKey("fontPath");
    this->size = std::stoi(parser.getValueOfKey("size"));
    f.set(parser.getValueOfKey("pos"));
    this->pos.first = std::stof(f.getValueOfKey("x"));
    this->pos.second = std::stof(f.getValueOfKey("y"));
}

Component::Text::Text(std::string componentName, std::string str, std::string fontPath,
int size, Color::Color color, std::pair<float, float> pos)
{
    this->componentName = componentName;
    this->type = listComponent::TEXT;
    this->display = true;
    this->str = str;
    this->fontPath = fontPath;
    this->size = size;
    this->color = color;
    this->pos = pos;
    //this->state.first = Component::State::ADD;
}

Component::Text::~Text()
{
    std::cout << "DELETED " << this->componentName << std::endl;
}

/*-------------------------Components-----------------------*/


std::shared_ptr<Components> findInComponents(std::vector<std::shared_ptr<Components>> components, std::string name)
{
    for (size_t i = 0; i != components.size(); i += 1) {
        if (components.at(i)->componentName == name)
            return components.at(i);
    }
    return NULL;
}
