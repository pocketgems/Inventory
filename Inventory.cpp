class Inventory {
    public:
        std::list<Item *> items; // in our current game design, each item is either a quest item or a normal item
        std::list<Item *> questItems; // for convenience, a subset of items, containing only quest items
        std::list<Item *> normalItems; // for convenience, a subset of items, containing only normal items

        Item *LastItemCollected() {
            return lastItemCollected;
        }

        void getitem(Item *i, int quantity) {
            for(int x = 0; x < quantity; ++x) {
                items.push_back(i);
                if (i->IsQuestItem()) {
                    questItems.push_back(i);
                } else {
                    normalItems.push_back(i);
                }
            }

            AchievementSystem::instance->DidModifyItem("gain", i->identifier, quantity);
            didpickupitem(i);
        }

        void loseitem(Item *i, int quantity) {
            for(int x = 0; x < quantity; ++x) {
                items.remove(i);
                if (i->IsQuestItem()) {
                    questItems.remove(i);
                } else {
                    normalItems.remove(i);
                }
            }

            AchievementSystem::instance->DidModifyItem("lose", i->identifier, quantity);
        }

        void didpickupitem(Item *i) {
            lastItemCollected = i;
        }


  // the user interface will display the last item we picked up
    private:
        Item *lastItemCollected;
};
