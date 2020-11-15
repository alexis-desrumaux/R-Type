/*
** EPITECH PROJECT, 2020
** test2
** File description:
** Parser
*/

#include "../include/Parser.hpp"

bool Parser::deleteKey(std::string key)
{
    std::string newBody = "";
    std::string keyStr = "";
    size_t i = 0; 

    if (this->isBodyAValue())
        return false;
    if (!this->isKeyExist(key))
        return false;
    for (; i != this->getNbOfKey(); i += 1) {
        keyStr.clear();
        this->extractKeyStr(keyStr, i + 1);
        if (this->extractKeyStr_key(keyStr) != key) {
            if (i == 0)
                newBody += keyStr;
            else
                newBody += " " + keyStr;
        }
    }
    this->body = newBody;
    return true;
}

bool Parser::isKeyExist(std::string key)
{
    std::string keyStr = "";
    size_t i = 0; 

    if (this->isBodyAValue())
        return false;
    
    for (; i != this->getNbOfKey(); i += 1) {
        keyStr.clear();
        this->extractKeyStr(keyStr, i + 1);
        if (this->extractKeyStr_key(keyStr) == key) {
            return true;
        }
    }
    return false;
}

size_t Parser::getNbOfKey()
{
    std::string e = "";
    size_t length = 0;

    if (this->isBodyAValue())
        return 0;
    for (size_t i = 1; this->extractKeyStr(e, i); e.clear(), i += 1, length += 1);
    return length;
}

void Parser::clear()
{
    this->body.clear();
}

std::string Parser::stringify()
{
    return this->body;
}

bool Parser::isBodyAValue()
{
    size_t index = 0;
    std::string sizeKeyStr = "";
    size_t sizeKey = 0;
    bool check = false;

    if (this->body.empty())
        return false;
    for (; index != this->body.size(); index += 1) {
        if (this->body.at(index) == '\"')
            break;
        sizeKeyStr += this->body.at(index);
    }
    sizeKey = std::stoul(sizeKeyStr);
    index += sizeKey + 2;
    if (index >= this->body.size())
        return true;
    return false;
}

std::string Parser::getValue()
{
    std::string value = "";
    std::string sizeStr = "";
    size_t size = 0;
    size_t i = 0;
    size_t j = 0;

    if (!this->isBodyAValue())
        return "";
    for (i = 0; this->body.at(i) != '\"'; i += 1)
        sizeStr += this->body.at(i);
    size = std::stoul(sizeStr);
    i += 1;
    j = i + size;
    for (; i != j; value += this->body.at(i), i += 1);
    return value;
}

std::string Parser::extractKeyStr_value(std::string &str)
{
    size_t index = 0;
    size_t end = 0;
    std::string sizeStr = "";
    size_t size = 0;

    for (; str.at(index) != '\"'; index += 1)
        sizeStr += str.at(index);
    size = std::stoul(sizeStr);
    index += 1;
    index += size + 2;
    sizeStr.clear();
    for (; str.at(index) != '\"'; index += 1)
        sizeStr += str.at(index);
    size = std::stoul(sizeStr);
    index += 1;
    end += index + size;
    return str.substr(index, size);
}

std::string Parser::extractKeyStr_key(std::string &str)
{
    size_t index = 0;
    size_t end = 0;
    std::string sizeStr = "";
    size_t size = 0;

    for (; str.at(index) != '\"'; index += 1)
        sizeStr += str.at(index);
    size = std::stoul(sizeStr);
    index += 1;
    end = index + size;
    return str.substr(index, size);
}

bool Parser::extractKeyStr(std::string &dest, size_t pos)
{
    size_t init = 0;
    size_t index = 0;
    std::string sizeStr = "";
    size_t size = 0;
    std::string keyStr = "";
    size_t currentPos = 0;

    for (; index < this->body.length() && currentPos != pos; currentPos += 1) {
        if (currentPos != 0)
            index += 1;
        init = index;
        sizeStr.clear();
        for (; this->body.at(index) != '\"'; index += 1)
            sizeStr += this->body.at(index);
        size = std::stoul(sizeStr);
        index += 1;
        index += size + 2;
        sizeStr.clear();
        for (; this->body.at(index) != '\"'; index += 1)
            sizeStr += this->body.at(index);
        size = std::stoul(sizeStr);
        index += 1;
        index += size + 1;
    }
    if (currentPos != pos)
        return false;
    for (; init != index; init += 1)
        dest += this->body.at(init);
    return true;
}

std::string Parser::getValueOfKey(std::string key)
{
    std::string keyStr = "";
    size_t i = 0;

    if (this->isBodyAValue())
        return "";

    for (; i != this->getNbOfKey(); i += 1) {
        keyStr.clear();
        this->extractKeyStr(keyStr, i + 1);
        if (this->extractKeyStr_key(keyStr) == key) {
            return this->extractKeyStr_value(keyStr);
        }
    }
    return "";
}

void Parser::setValue(std::string value)
{
    this->body.clear();
    this->body += std::to_string(value.size());
    this->body += "\"" + value + "\"";
}

void Parser::set(std::string data)
{
    this->body = data;
}

void Parser::setKey(std::string key, std::string value)
{
    this->addKey(key, value);
}

void Parser::addKey(std::string key, std::string value)
{
    if (this->isBodyAValue())
        this->body.clear();
    if (this->isKeyExist(key))
        this->deleteKey(key);
    if (this->body.empty()) {
        this->body +=  std::to_string(key.size()) + "\"" + key + "\"" + ":" + std::to_string(value.size()) + "\"" + value + "\"";
    } else {
        this->body += " " + std::to_string(key.size()) + "\"" + key + "\"" + ":" + std::to_string(value.size()) + "\"" + value + "\"";
    }
}

Parser::Parser(const std::string parserData)
{
    this->body = parserData;
}

Parser::Parser(const Parser &parser)
{
    this->body = parser.body;
}

Parser::Parser()
{

}

Parser::~Parser()
{
}
