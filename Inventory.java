class Inventory {
  public List<Item> items; // in our current game design, each item is either a quest item or a normal item
  public List<Item> questItems; // for convenience, a subset of items, containing only quest items
  public List<Item> normalItems; // for convenience, a subset of items, containing only normal items

  // the user interface will display the last item we picked up
  private Item lastItemCollected;
  public Item LastItemCollected() {
    return lastItemCollected;
  }

  public void getitem(Item i, int quantity) {
    for(int x = 0; x < quantity; ++x) {
      items.add(i);
      if (i.IsQuestItem()) {
        questItems.add(i);
      } else {
        normalItems.add(i);
      }
    }

    AchievementSystem.instance.DidModifyItem("gain", i.identifier, quantity);
    didpickupitem(i);
  }

  public void loseitem(Item i, int quantity) {
    for(int x = 0; x < quantity; ++x) {
      items.remove(i);
      if (i.IsQuestItem()) {
        questItems.remove(i);
      } else {
        normalItems.remove(i);
      }
    }

    AchievementSystem.instance.DidModifyItem("lose", i.identifier, quantity);
  }

  public void didpickupitem(Item i) {
    lastItemCollected = i;
  }
}
