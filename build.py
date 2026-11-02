import os
import glob
import sys

from enum import Enum

CC = "gcc"
CFLAGS = "-Wall -g"

BUILD = "./build/out/"
EXECUTABLE_NAME = "game_engine"


class BashColors(Enum):
    RESET = "\033[0m"
    BOLD = "\033[1m"
    BLACK = "\033[30m"
    RED = "\033[31m"
    GREEN = "\033[32m"
    YELLOW = "\033[33m"
    BLUE = "\033[34m"
    PURPLE = "\033[35m"
    CYAN = "\033[36m"
    WHITE = "\033[37m"


class ObjectFile:
    def __init__(self, file_dir: str, out_dir: str, args: str):
        self.file_dir = file_dir
        self.out_dir = out_dir
        self.args = args

    def compile(self) -> int:
        return os.system(f"{CC} {CFLAGS} {self.args} {self.file_dir} -o {self.out_dir}")


def change_file_extension(file: str, extension: str) -> str:
    return f"{file[: file.rfind('.') + 1]}{extension}"


def glob_object_files(dir: str, extension: str, args: str) -> list[ObjectFile]:
    files: list[str] = glob.glob(f"{dir}*.{extension}")
    object_file: list[ObjectFile] = []
    for file in files:
        file_name = os.path.basename(file)
        object_file.append(
            ObjectFile(file, f"{BUILD}{change_file_extension(file_name, 'o')}", args)
        )
    return object_file


def check_file_stamp(in_dir_file: str, out_dir_file: str) -> int:
    if not os.path.isfile(out_dir_file):
        return 0
    if os.path.getmtime(out_dir_file) <= os.path.getmtime(in_dir_file):
        return 0
    return 1


def build() -> int:
    objects_files = glob_object_files("./src/", "c", "-c")
    executable = ObjectFile("", f"{BUILD}bin/{EXECUTABLE_NAME}", "")

    n: int = 0
    for file in objects_files:
        if check_file_stamp(file.file_dir, file.out_dir):
            print(
                f"{BashColors.YELLOW.value}{BashColors.BOLD.value}[{n}/{len(objects_files)}] No need to compile CXX object {file.out_dir}{BashColors.RESET.value}"
            )
            continue

        executable.file_dir += f"{file.out_dir} "
        if file.compile():
            print(
                f"{BashColors.RED.value}{BashColors.BOLD.value}[{n}/{len(objects_files)}] Couldn't compile CXX object {file.out_dir}{BashColors.RESET.value}"
            )
            sys.exit(1)
        print(
            f"{BashColors.GREEN.value}{BashColors.BOLD.value}[{n}/{len(objects_files)}] Compiled CXX object {file.out_dir}{BashColors.RESET.value}"
        )
        n += 1
    if executable.compile():
        print(
            f"{BashColors.RED.value}{BashColors.BOLD.value}[{n}/{len(objects_files)}] Couldn't compile CXX binary{BashColors.RESET.value}"
        )
        sys.exit(1)
    print(
        f"{BashColors.GREEN.value}{BashColors.BOLD.value}[{n}/{len(objects_files)}] Compiled CXX binary{BashColors.RESET.value}"
    )

    return 0

args: list[str] = sys.argv
match args[0]:
_:
    build()

