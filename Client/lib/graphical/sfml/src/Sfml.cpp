/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Sfml
*/

#include "../include/SFML.hpp"
#include "../include/Components.hpp"
#include <chrono>

sf::Color convertColorFromComponent(Component::Color::Color color)
{
    switch (color) {
        case Component::Color::White:
            return sf::Color::White;
        case Component::Color::Black:
            return sf::Color::Black;
        case Component::Color::Red:
            return sf::Color::Red;
        case Component::Color::Green:
            return sf::Color::Green;
        case Component::Color::Blue:
            return sf::Color::Blue;
    }
    return sf::Color::Black;
}

std::string SFKeyToString(unsigned int keycode)
{
    std::string keyStr;

    switch (keycode) {
        case sf::Keyboard::A: keyStr = "A"; break;
        case sf::Keyboard::B: keyStr = "B"; break;
        case sf::Keyboard::C: keyStr = "C"; break;
        case sf::Keyboard::D: keyStr = "D"; break;
        case sf::Keyboard::E: keyStr = "E"; break;
        case sf::Keyboard::F: keyStr = "F"; break;
        case sf::Keyboard::G: keyStr = "G"; break;
        case sf::Keyboard::H: keyStr = "H"; break;
        case sf::Keyboard::I: keyStr = "I"; break;
        case sf::Keyboard::J: keyStr = "J"; break;
        case sf::Keyboard::K: keyStr = "K"; break;
        case sf::Keyboard::L: keyStr = "L"; break;
        case sf::Keyboard::M: keyStr = "M"; break;
        case sf::Keyboard::N: keyStr = "N"; break;
        case sf::Keyboard::O: keyStr = "O"; break;
        case sf::Keyboard::P: keyStr = "P"; break;
        case sf::Keyboard::Q: keyStr = "Q"; break;
        case sf::Keyboard::R: keyStr = "R"; break;
        case sf::Keyboard::S: keyStr = "S"; break;
        case sf::Keyboard::T: keyStr = "T"; break;
        case sf::Keyboard::U: keyStr = "U"; break;
        case sf::Keyboard::V: keyStr = "V"; break;
        case sf::Keyboard::W: keyStr = "W"; break;
        case sf::Keyboard::X: keyStr = "X"; break;
        case sf::Keyboard::Y: keyStr = "Y"; break;
        case sf::Keyboard::Z: keyStr = "Z"; break;
        case sf::Keyboard::Escape: keyStr = "Escape"; break;
        case sf::Keyboard::LControl: keyStr = "LControl"; break;
        case sf::Keyboard::LShift: keyStr = "LShift"; break;
        case sf::Keyboard::LAlt: keyStr = "LAlt"; break;
        case sf::Keyboard::LSystem: keyStr = "LSystem"; break;
        case sf::Keyboard::RControl: keyStr = "RControl"; break;
        case sf::Keyboard::RShift: keyStr = "RShift"; break;
        case sf::Keyboard::RAlt: keyStr = "RAlt"; break;
        case sf::Keyboard::RSystem: keyStr = "RSystem"; break;
        case sf::Keyboard::Menu: keyStr = "Menu"; break;
        case sf::Keyboard::LBracket: keyStr = "LBracket"; break;
        case sf::Keyboard::RBracket: keyStr = "RBracket"; break;
        case sf::Keyboard::SemiColon: keyStr = ";"; break;
        case sf::Keyboard::Comma: keyStr = ","; break;
        case sf::Keyboard::Period: keyStr = "."; break;
        case sf::Keyboard::Quote: keyStr = "\'"; break;
        case sf::Keyboard::Slash: keyStr = "/"; break;
        case sf::Keyboard::BackSlash: keyStr = "\\"; break;
        case sf::Keyboard::Tilde: keyStr = "~"; break;
        case sf::Keyboard::Equal: keyStr = "="; break;
        case sf::Keyboard::Dash: keyStr = "-"; break;
        case sf::Keyboard::Space: keyStr = "Space"; break;
        case sf::Keyboard::Return: keyStr = "Return"; break;
        case sf::Keyboard::BackSpace: keyStr = "Back"; break;
        case sf::Keyboard::Tab: keyStr = "Tab"; break;
        case sf::Keyboard::PageUp: keyStr = "Page Up"; break;
        case sf::Keyboard::PageDown: keyStr = "Page Down"; break;
        case sf::Keyboard::End: keyStr = "End"; break;
        case sf::Keyboard::Home: keyStr = "Home"; break;
        case sf::Keyboard::Insert: keyStr = "Insert"; break;
        case sf::Keyboard::Delete: keyStr = "Delete"; break;
        case sf::Keyboard::Add: keyStr = "+"; break;
        case sf::Keyboard::Subtract: keyStr = "-"; break;
        case sf::Keyboard::Multiply: keyStr = "*"; break;
        case sf::Keyboard::Divide: keyStr = "/"; break;
        case sf::Keyboard::Left: keyStr = "Left"; break;
        case sf::Keyboard::Right: keyStr = "Right"; break;
        case sf::Keyboard::Up: keyStr = "Up"; break;
        case sf::Keyboard::Down: keyStr = "Down"; break;
        case sf::Keyboard::Numpad0: keyStr = "NP 0"; break;
        case sf::Keyboard::Numpad1: keyStr = "NP 1"; break;
        case sf::Keyboard::Numpad2: keyStr = "NP 2"; break;
        case sf::Keyboard::Numpad3: keyStr = "NP 3"; break;
        case sf::Keyboard::Numpad4: keyStr = "NP 4"; break;
        case sf::Keyboard::Numpad5: keyStr = "NP 5"; break;
        case sf::Keyboard::Numpad6: keyStr = "NP 6"; break;
        case sf::Keyboard::Numpad7: keyStr = "NP 7"; break;
        case sf::Keyboard::Numpad8: keyStr = "NP 8"; break;
        case sf::Keyboard::Numpad9: keyStr = "NP 9"; break;
        case sf::Keyboard::F1: keyStr = "F1"; break;
        case sf::Keyboard::F2: keyStr = "F2"; break;
        case sf::Keyboard::F3: keyStr = "F3"; break;
        case sf::Keyboard::F4: keyStr = "F4"; break;
        case sf::Keyboard::F5: keyStr = "F5"; break;
        case sf::Keyboard::F6: keyStr = "F6"; break;
        case sf::Keyboard::F7: keyStr = "F7"; break;
        default:
        keyStr = "";
    }
    return keyStr;
}

int SFML::SFML::draw(void)
{
    for (size_t i = 0; i != this->lComponents.size(); i += 1) {
        this->lComponents.at(i)->draw(this->window);
    }
    return 0;
}

int SFML::SFML::manageUpdate(std::vector<std::shared_ptr<Components>> update)
{
    for (size_t i = 0; i != update.size(); i += 1) {
        if (findInLComponents(this->lComponents, update.at(i)->componentName) != NULL) {
            findInLComponents(this->lComponents, update.at(i)->componentName)->display = update.at(i)->display;
            switch (update.at(i)->type)
            {
            case listComponent::TEXT:
            {
                if (update.at(i)->serialize() != findInLComponents(this->lComponents, update.at(i)->componentName)->serializedComponent) {
                    std::shared_ptr<Component::Text> text = std::dynamic_pointer_cast<Component::Text>(update.at(i));
                    std::shared_ptr<LComponent::Text> c = std::dynamic_pointer_cast<LComponent::Text>(findInLComponents(this->lComponents, text->componentName));
                    c->update(text);
                }
                break;
            }
            case listComponent::SPRITE:
            {
                if (update.at(i)->serialize() != findInLComponents(this->lComponents, update.at(i)->componentName)->serializedComponent) {
                    std::shared_ptr<Component::Sprite> sprite = std::dynamic_pointer_cast<Component::Sprite >(update.at(i));
                    std::shared_ptr<LComponent::Sprite> c = std::dynamic_pointer_cast<LComponent::Sprite>(findInLComponents(this->lComponents, sprite->componentName));
                    c->update(sprite);
                }
                break;
            }
            case listComponent::AUDIO:
            {
                if (update.at(i)->serialize() != findInLComponents(this->lComponents, update.at(i)->componentName)->serializedComponent) {
                    std::shared_ptr<Component::Audio> audio = std::dynamic_pointer_cast<Component::Audio>(update.at(i));
                    std::shared_ptr<LComponent::Audio> c = std::dynamic_pointer_cast<LComponent::Audio>(findInLComponents(this->lComponents, audio->componentName));
                    c->update(audio);
                }
                break;
            }
            default:
                break;
            }
        }
    }
    return 0;
}

size_t findLComponents_index(std::vector<std::shared_ptr<SFML::LComponents>>&lcomponent, std::string name)
{
    for (size_t i = 0; !lcomponent.empty() && i != lcomponent.size(); i += 1) {
        if (lcomponent.at(i)->componentName == name)
            return i;
    }
    return -1;
}

size_t findComponents_index(std::vector<std::shared_ptr<Components>> &components, std::string name)
{
    for (size_t i = 0; !components.empty() && i != components.size(); i += 1) {
        if (components.at(i)->componentName == name)
            return i;
    }
    return -1;
}

std::shared_ptr<SFML::LComponents> createNewLComponent(std::shared_ptr<Components> AComponent)
{
    listComponent::listComponent type = AComponent->type;
    std::shared_ptr<SFML::LComponents> newLComponent = nullptr;

    switch (type)
    {
        case listComponent::listComponent::SPRITE:
            newLComponent = std::make_shared<SFML::LComponent::Sprite>(std::dynamic_pointer_cast<Component::Sprite>(AComponent));
            break;
        case listComponent::listComponent::TEXT:
            newLComponent = std::make_shared<SFML::LComponent::Text>(std::dynamic_pointer_cast<Component::Text>(AComponent));
            break;
        case listComponent::listComponent::AUDIO:
            newLComponent = std::make_shared<SFML::LComponent::Audio>(std::dynamic_pointer_cast<Component::Audio>(AComponent));
            break;
        default:
            break;
    }
    return newLComponent;
}

void debug_dispNameLComponents(std::vector<std::shared_ptr<SFML::LComponents>> &lcomponents)
{
    for (size_t i = 0; i != lcomponents.size(); i += 1) {
        std::cout << lcomponents.at(i)->componentName << std::endl;
        std::cout << "---------------------------" << std::endl;
        std::cout << lcomponents.at(i)->serializedComponent << std::endl;
    }
}

void SFML::SFML::checkForMovedComponents(std::vector<std::shared_ptr<Components>>& components)
{
    std::vector<std::shared_ptr<LComponents>>newLcomponents;
    std::vector<size_t> positions;
    size_t indexOfLComponent = 0;
    bool moved = false;

    for (size_t i = 0; i != components.size(); i += 1) {
        indexOfLComponent = findLComponents_index(this->lComponents, components.at(i)->componentName);
        if (indexOfLComponent != (size_t)-1) {
            if (i != indexOfLComponent) {
                moved = true;
            }
            positions.push_back(indexOfLComponent);
        }
    }
    if (moved == true) {
        for (size_t i = 0; i != positions.size(); i += 1) {
            newLcomponents.push_back(this->lComponents.at(positions.at(i)));
        }
        this->lComponents = newLcomponents;
    }
}

void SFML::SFML::checkForDeletedComponents(std::vector<std::shared_ptr<Components>>& components)
{
    size_t indexOfComponent = 0;

    for (size_t i = 0; i != this->lComponents.size(); i += 1) {
        indexOfComponent = findComponents_index(components, this->lComponents.at(i)->componentName);
        if (indexOfComponent == (size_t)-1) {
            this->lComponents.erase(this->lComponents.begin() + i);
        }
    }
}

void SFML::SFML::checkForNewComponents(std::vector<std::shared_ptr<Components>> &components)
{
    size_t indexOfLComponent = 0;

    for (size_t i = 0; i != components.size(); i += 1) {
        indexOfLComponent = findLComponents_index(this->lComponents, components.at(i)->componentName);
        if (indexOfLComponent == (size_t)-1) {
            this->lComponents.insert(this->lComponents.begin() + i, createNewLComponent(components.at(i)));
        }
    }
}

void resetEventStruct(std::shared_ptr<eventType_t> eventStruct)
{
    eventStruct->isClosed = false;
    eventStruct->isKeyPressed = false;
    eventStruct->isKeyReleased = false;
    eventStruct->isMouseBtnPressed = false;
    eventStruct->isMouseBtnReleased = false;
    eventStruct->isMouseMoved = false;
    eventStruct->keyPressed = "";
    eventStruct->mouseButtonPressedCoordinates.x = 0;
    eventStruct->mouseButtonPressedCoordinates.y = 0;
    eventStruct->mouseButtonPressedType = Mouse::Button::Type::NONE;
    eventStruct->mouseCoordinates.x = 0;
    eventStruct->mouseCoordinates.y = 0;
}

void fillEventStruct(std::shared_ptr<eventType_t> eventStruct, sf::Event event, std::shared_ptr<sf::RenderWindow> window)
{
    switch (event.type)
    {
        case sf::Event::Closed:
            eventStruct->isClosed = true;
            break;
        case sf::Event::MouseButtonPressed:
            eventStruct->isMouseBtnPressed = true;
            std::cout << "window size width: " << window->getSize().x << " height: " << window->getSize().y << std::endl;

            eventStruct->mouseButtonPressedCoordinates.x = (event.mouseButton.x * 1920) / window->getSize().x;
            eventStruct->mouseButtonPressedCoordinates.y = (event.mouseButton.y * 1080) / window->getSize().y;
            if (event.mouseButton.button == sf::Mouse::Left)
                eventStruct->mouseButtonPressedType = Mouse::Button::Type::LEFT;
            if (event.mouseButton.button == sf::Mouse::Middle)
                eventStruct->mouseButtonPressedType = Mouse::Button::Type::MIDDLE;
            if (event.mouseButton.button == sf::Mouse::Right)
                eventStruct->mouseButtonPressedType = Mouse::Button::Type::RIGHT;
            break;
        case sf::Event::MouseButtonReleased:
            eventStruct->isKeyReleased = true;
            break;
        case sf::Event::MouseMoved:
            eventStruct->isMouseMoved = true;
            eventStruct->mouseCoordinates.x = event.mouseMove.x;
            eventStruct->mouseCoordinates.y = event.mouseMove.y;
            break;
        case sf::Event::KeyPressed:
            eventStruct->isKeyPressed = true;
            eventStruct->keyPressed = SFKeyToString(event.key.code);
            break;
        case sf::Event::KeyReleased:
            eventStruct->isKeyReleased = true;
            break;
        default:
            break;
    }
}

std::shared_ptr<eventType_t> SFML::SFML::display(std::vector<std::shared_ptr<Components>> components)
{
    sf::Event event;
    std::string keyPressed = "";

    this->checkForNewComponents(components);
    this->checkForDeletedComponents(components);
    this->checkForMovedComponents(components);

    resetEventStruct(eventStruct);
    while (this->window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->isRunning = false;
            this->window->close();
        }
        fillEventStruct(this->eventStruct, event, this->window);
    }
    this->window->clear();
    manageUpdate(components);
    draw();
    this->window->display();
    return this->eventStruct;
}

void deleteUnusedLComponents(std::vector<SFML::LComponents *>&lComponents, std::vector<size_t> listLComponentSavedIndex)
{
    for (size_t j = 0; j != lComponents.size(); j += 1) {
        bool found = false;
        for (size_t i = 0; i != listLComponentSavedIndex.size(); i += 1) {
            if (j == listLComponentSavedIndex.at(i)) {
                found = true;
                break;
            }
        }
        if (!found)
            delete lComponents.at(j);
    }
}

SFML::SFML::SFML()
{
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "R-Type");
    this->name = "";
    this->type = "SFML";
    this->eventStruct = std::make_shared<eventType_t>();
    resetEventStruct(this->eventStruct);
    this->window->setFramerateLimit(60);
}

SFML::SFML::~SFML()
{
    std::cout << "DELETED SFML" << std::endl;
}

extern "C"
{
	IGLib *createLib()
	{
		return new SFML::SFML();
	}
}