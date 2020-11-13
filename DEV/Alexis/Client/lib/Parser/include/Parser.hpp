/*
** EPITECH PROJECT, 2020
** test2
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>

class Parser {
    public:
        Parser();
        Parser(const Parser &parser);
        Parser(const std::string parserData);
        ~Parser();
        void addKey(std::string key, std::string value);
        void setKey(std::string key, std::string value);
        bool deleteKey(std::string key);
        std::string getValueOfKey(std::string key);
        void setValue(std::string value);
        void set(std::string data);
        std::string getValue();
        std::string stringify();
        void clear();
        size_t getNbOfKey();
        bool isKeyExist(std::string);

    protected:
    private:
    //functions
        bool isBodyAValue();
        bool extractKeyStr(std::string &dest, size_t pos);
        std::string extractKeyStr_key(std::string &str);
        std::string extractKeyStr_value(std::string &str);
    //data
        std::string body;
};

#endif /* !PARSER_HPP_ */
