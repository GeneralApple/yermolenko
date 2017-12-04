from maze_classes import Maze, factory, factory_v2, MazeBuilder
from maze_components import Room, Door, Wall, \
    EnchantedWall, EnchantedDoor, EnchantedRoom, \
    RoomWithBomb, DoorWithBomb, WallWithBomb


def make_maze1_basic():
    maze, r1, r2 = Maze(), Room(1), Room(2)
    door = Door(r1, r2)

    r1.set_side('north', Wall())
    r1.set_side('east', door)
    r1.set_side('south', Wall())
    r1.set_side('west', Wall())

    r2.set_side('north', Wall())
    r2.set_side('east', Wall())
    r2.set_side('south', Wall())
    r2.set_side('west', door)

    maze.add_room(r1)
    maze.add_room(r2)

    return maze


def make_maze2_factory():
    ench_factory = factory('enchanted')
    maze, r1, r2 = Maze(), ench_factory.get_room(1), ench_factory.get_room(2)
    door = ench_factory.get_door(r1, r2)

    r1.set_side('north', ench_factory.get_wall())
    r1.set_side('east', door)
    r1.set_side('south', ench_factory.get_wall())
    r1.set_side('west', ench_factory.get_wall())

    r2.set_side('north', ench_factory.get_wall())
    r2.set_side('east', ench_factory.get_wall())
    r2.set_side('south', ench_factory.get_wall())
    r2.set_side('west', door)

    maze.add_room(r1)
    maze.add_room(r2)

    return maze


def make_maze2_v2_factory_prototype():
    # using the fact that class is ordinary object, not just type
    Room, Door, Wall = factory_v2('bombed')
    maze, r1, r2 = Maze(), Room(1), Room(2)
    door = Door(r1, r2)

    r1.set_side('north', Wall())
    r1.set_side('east', door)
    r1.set_side('south', Wall())
    r1.set_side('west', Wall())

    r2.set_side('north', Wall())
    r2.set_side('east', Wall())
    r2.set_side('south', Wall())
    r2.set_side('west', door)

    maze.add_room(r1)
    maze.add_room(r2)

    return maze


def make_maze3_builder():
    builder = MazeBuilder(room_creator=EnchantedRoom,
                          door_creator=EnchantedDoor,
                          wall_creator=EnchantedWall)
    builder.build_room(1)
    builder.build_room(2)
    builder.build_room(3)
    builder.build_door(1, 2)
    builder.build_door(2, 3)

    return builder.get_maze()


if __name__ == '__main__':
    print('\nBasic example:\n')
    print(make_maze1_basic())
    print('\nFactory example:\n')
    print(make_maze2_factory())
    print('\nAnother factory approach:\n')
    print(make_maze2_v2_factory_prototype())
    print('\nWith builder:\n')
    print(make_maze3_builder())

