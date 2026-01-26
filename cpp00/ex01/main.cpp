/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:34:03 by gamorcil          #+#    #+#             */
/*   Updated: 2026/01/26 08:34:04 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

using namespace std;

int main(int argc, char **argv)
{
    PhoneBook phoneBook;
    string command;

    (void)argv;
    if (argc != 1)
    {
        cout << "Usage: ./phonebook" << endl;
        return 1;
    }
    cout << "Welcome to your PhoneBook!" << endl;
    cout << "Available commands: ADD, SEARCH, EXIT" << endl;

    while (true)
    {
        cout << "Enter command: ";
        if (!getline(cin, command))
        {
            cout << "Exiting PhoneBook. Goodbye!" << endl;
            break;
        }

        if (command == "ADD")
        {
            phoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContacts();
        }
        else if (command == "EXIT")
        {
            cout << "Exiting PhoneBook. Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid command. Please try again." << endl;
        }
    }
    return 0;
}
