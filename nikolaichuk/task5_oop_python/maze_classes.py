from maze_components import Room, Door, Wall, \
    EnchantedDoor, EnchantedRoom, EnchantedWall, \
    RoomWithBomb, WallWithBomb, DoorWithBomb


class Maze:
    def __init__(self):
        self.maze = []

    def add_room(self, room):
        self.maze.append(room)

    def get_room(self, num):
        return self.maze[num-1]

    def __str__(self):
        ans = "Ordinary maze.\n"
        for room in self.maze:
            ans = ans + str(room) + '\n'

        return ans


class MazeFactory:
    def __init__(self, room_class=Room, wall_class=Wall, door_class=Door):
        self.get_room = room_class
        self.get_wall = wall_class
        self.get_door = door_class


class MazeBuilder:
    def __init__(self, room_creator=Room, door_creator=Door, wall_creator=Wall):
        self.make_room = room_creator
        self.make_door = door_creator
        self.make_wall = wall_creator
        self._current_maze = Maze()

    def build_room(self, room_num):
        room = self.make_room(room_num)
        room.set_side('north', self.make_wall())
        room.set_side('south', self.make_wall())
        room.set_side('east', self.make_wall())
        room.set_side('west', self.make_wall())
        self._current_maze.add_room(room)

    def build_door(self, room1, room2):
        r1 = self._current_maze.get_room(room1)
        r2 = self._current_maze.get_room(room2)

        d = self.make_door(r1, r2)
        r1.set_side(self._common_wall(r1, r2), d)
        r2.set_side(self._common_wall(r2, r1), d)

    def get_maze(self):
        return self._current_maze

    def _common_wall(self, room1, room2):
        # TODO: implement normal common_wal()
        # for now it is just one-line maze
        if room1.number() < room2.number():
            return 'west'
        else:
            return 'east'


def factory(specifier):
    if specifier == "enchanted":
        return MazeFactory(room_class=EnchantedRoom,
                           door_class=EnchantedDoor,
                           wall_class=EnchantedWall)
    elif specifier == "bombed":
        return MazeFactory(room_class=RoomWithBomb,
                           door_class=DoorWithBomb,
                           wall_class=WallWithBomb)
    else:
        return MazeFactory()


def factory_v2(specifier):
    """Return `room`, `door`, `wall`."""
    if specifier == "enchanted":
        return EnchantedRoom, EnchantedDoor, EnchantedWall
    elif specifier == "bombed":
        return RoomWithBomb, DoorWithBomb, WallWithBomb
    else:
        return Room, Door, Wall
