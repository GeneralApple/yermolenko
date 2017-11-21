DIRECTIONS = {"north": 0,
              "south": 1,
              "west" : 2,
              "east" : 3}

SIDES = ['north', 'south', 'west', 'east']


class MapSite:
    def __init__(self):
        pass

    def enter(self):
        raise NotImplementedError


class Room(MapSite):
    def __init__(self, room_num):
        super().__init__()
        self._room_num = room_num
        self._sides = [None, None, None, None]

    def get_side(self, direction):
        return self._sides[DIRECTIONS[direction.lower()]]

    def set_side(self, direction: str, side):
        self._sides[DIRECTIONS[direction.lower()]] = side

    def number(self):
        return self._room_num

    def enter(self):
        raise NotImplementedError

    def __str__(self):
        ans = "Room #{}.\n".format(self._room_num)
        for i, side in enumerate(self._sides):
            ans += "\tOn <{:^8}> {}\n".format(SIDES[i], str(side))

        return ans


class Wall(MapSite):
    def __init__(self):
        super().__init__()

    def enter(self):
        raise NotImplementedError

    def __str__(self):
        return "Just wall, nothing unusual."


class Door(MapSite):
    def __init__(self, room1, room2, opened=False):
        super().__init__()
        self._room1 = room1
        self._room2 = room2
        self.opened = opened

    def enter(self):
        raise NotImplementedError

    def __str__(self):
        return "Door between rooms {} and {}. Currently {}.".format(
            self._room1.number(),
            self._room2.number(),
            "locked" if self.opened else "closed"
        )


class EnchantedWall(Wall):
    def __init__(self):
        super().__init__()

    def enter(self):
        raise NotImplementedError

    def __str__(self):
        return "No ordinary wall. Rainbow sparks cover it, hypnotizing you."


class EnchantedDoor(Door):
    def __init__(self, room1, room2, spell='not_a_spell_yet', enchanted=True):
        super().__init__(room1, room2)
        self.enchanted = enchanted
        self.__opening_spell = spell

    def enter(self):
        raise NotImplementedError

    def __str__(self):
        ans = "Magical door between rooms {} and {}. Currently {}.".format(
            self._room1.number(),
            self._room2.number(),
            "locked" if self.opened else "closed"
        )

        if self.enchanted:
            ans += "\nPower can be felt emanating from door, with visible " \
                   "waves of force wondering across its surface."
        else:
            ans += "\nDoor looks quite ordinary and harmless."

        return ans


class EnchantedRoom(Room):
    def __init__(self, room_num, spell='not_a_spell_yet'):
        super().__init__(room_num)
        self._spell = spell

    def enter(self):
        raise NotImplementedError

    def __str__(self):
        ans = "Enchanted room #{}. {} was casted on it.\n".format(
            self._room_num, self._spell)
        for i, side in enumerate(self._sides):
            ans += "\tOn <{:^8}> {}\n".format(SIDES[i], str(side))

        return ans


class RoomWithBomb(Room):
    def __init__(self, room_num, mined=True):
        super().__init__(room_num)
        self.mined = mined

    def enter(self):
        raise NotImplementedError

    def __str__(self):
        ans = "Room #{}.\n".format(self._room_num)
        if self.mined:
            ans += 'Intuition tells you, that sign "BEWARE MINES" ' \
                   'is here not just to prank.\n'
        else:
            ans += 'Your "chuika" is silent. Maybe giant sign ' \
                   '"BEWARE MINES" is nothing but decoy.\n'
        for i, side in enumerate(self._sides):
            ans += "\tOn <{:^8}> {}\n".format(SIDES[i], str(side))

        return ans


class WallWithBomb(Wall):
    def __init__(self):
        super().__init__()

    def enter(self):
        raise NotImplementedError

    def __str__(self):
        return "Wall with a bomb, whatever the heck it means."


class DoorWithBomb(Door):
    def __init__(self, room1, room2, mined=True):
        super().__init__(room1, room2)
        self.mined = mined

    def enter(self):
        raise NotImplementedError

    def __str__(self):
        ans = "Door between rooms {} and {}. Currently {}.".format(
            self._room1.number(),
            self._room2.number(),
            "locked" if self.opened else "closed"
        )

        if self.mined:
            ans += "Scary detonators and wires are all across the handle." \
                   "Better not touch it."
        else:
            ans += "Scraps of wires are hanging on it. Seems like it is defused" \
                   "already and can be safely opened."

        return ans
