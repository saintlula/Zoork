//
// Created by Ehlinaz Duru Yildirim on 2/6/2025.
//

//RoomBuilder.cpp
#include "RoomBuilder.h"

//Room bulding.
Room* RoomBuilder::buildWorld()
{
    Room* room1 = new Room(1, "The Foyer", "A small marble foyer with a dusty chandelier in the middle that barely flickers. ", false, "");

    Room* room2 = new Room(2, "Library", "Rows and rows of ancient books, looks so endless that surely there is something you can use here. Smells like parchment.", false, "",
                "You can look at the bookshelves. Would you like to look? (look)");
    room2->addItem("case key");

    Room* room3 = new Room(3, "Reptile House", "A dim and humid room. It echoes with an occasional hiss coming from.. Somewhere. It's creepy. There is a marble slab right in the middle of the room. It looks so out of place. With a chest on top of it?", false, "",
                                "The chest sparks your curiosity. A little look won't hurt.. Right? (reveal");

    Room* room4 = new Room(4, "Armory", "Rusty weapons and cracked shields lie in piles all around, seemingly untouched for ages. There wouldn't be anything still useful here.", false, "");

    Room* room5 = new Room(5, "The Taxidermy", "Glassy eyes stare at you from every wall. Each creature seems to be frozen mid-snarl. They look too lifelike for comfort", false, "",
                         "But you're curiosity overpowers your fear. Would you like to look around? (look)");

    Room* room6 = new Room(6, "Servants' Quarters","There's 6 neatly made, narrow beds and a large table in the middle of the room. A silver tray on the table, the food on it seemingly untouched. You're starving so bad it looks appealing almost.", false, "" );
    Room* room7 = new Room(7, "The Nursery", "Tiny chairs, broken toys and a doll that is.. Slowly turning it's head. It should not be moving", false, "");
    Room* room8 = new Room(8, "The Mirror Hall", "Tall mirrors line the narrow hallway, all cracked. Your reflection never quite moves when you do.", false, "");
    Room* room9 = new Room(9, "The Aviary", "The air is thick with feathers and a grainy smell. Empty cages in the room swing gently.There's no wind", false, "");
    Room* room10 = new Room(10, "Observatory", "The ceiling is a shattered thick glass dome, so thick that you can't see through it. Star chart scrolls lie scattered across a warped wooden table. A brass telescope point skywards, towards the broken dome.", false, "" );

    //Connecting the rooms
    //Foyer
    room1->connections.setExit("north", room2); // → Library//
    room1->connections.setExit("east", room3);  // → Reptile House//
    room1->connections.setExit("west", room6);  // → Servants' Quarters//
    room1->connections.setExit("south", room7); // ->  Nursery//
    //Library
    room2->connections.setExit("south", room1); // → Foyer//
    room2->connections.setExit("east", room4);  // → Armory//
    room2->connections.setExit("north", room7); // → Observatory//
    room2->connections.setExit("west", room6);  // → Servants' Quarters
    //Reptile
    room3->connections.setExit("west", room1);  // → Foyer//
    room3->connections.setExit("north", room5); // → Taxidermy
    room3->connections.setExit("east", room9);  // → Aviary
    room3->connections.setExit("south", room10); // → Observatory
    //Armory
    room4->connections.setExit("west", room2);  // → Library//
    room4->connections.setExit("south", room6); // → Servants' Quarters
    room4->connections.setExit("east", room10); // → Observatory
    room4->connections.setExit("north", room9); // → Aviary
    //Taxidermy
    room5->connections.setExit("south", room3); // → Reptile House
    room5->connections.setExit("east", room7);  // → Nursery
    room5->connections.setExit("north", room9); // → Aviary
    room5->connections.setExit("west", room5);  // → Taxidermy
    //Servant Q.
    room6->connections.setExit("north", room4); // → Armory
    room6->connections.setExit("west", room7);  // → Nursery
    room6->connections.setExit("south", room8); // Servants' Quarters → Mirror Hall
    room6->connections.setExit("east", room1); //Foyer//
    //Nursery
    room7->connections.setExit("west", room5);  // → Taxidermy
    room7->connections.setExit("south", room9); // → Aviary
    room7->connections.setExit("east", room10); // → Observatory
    room7->connections.setExit("north", room1);  // → Foyer//
    //mirror hall
    room8->connections.setExit("north", room6); // Mirror Hall → Servants' Quarters
    //Aviary
    room9->connections.setExit("west", room3);  // → Reptile House
    room9->connections.setExit("north", room5); // → Taxidermy
    room9->connections.setExit("east", room7); // → Nursery
    room9->connections.setExit("south", room9); // → Aviary
    //Observitory
    room10->connections.setExit("west", room4); // → Armory
    room10->connections.setExit("south", room2); // → Library//
    room10->connections.setExit("east", room7); // → Nursery
    room10->connections.setExit("north", room3);  // → Reptile House//

    return room1;
}