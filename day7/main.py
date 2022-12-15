dirs = {}
path = "/"
lines = None

with open("input.txt") as f:
    lines = f.readlines()

def append_size(size):
    global path, dirs
    if path in dirs:
        dirs[path] += size
    else:
        dirs[path] = size

def process_line(line):
    global dirs, path

    words = line.split()
    if words[0] == "$":
        if words[1] == "cd":
            if words[2] == "..":
                old_path = path
                path = "/".join(path.split("/")[0:-1])
                if path == "":
                    path = "/"
                append_size(dirs[old_path])
            else:
                path += ("/" if path != "/" else "") + words[2]
    elif words[0] != "dir":
        append_size(int(words[0]))

for line in lines[1:]:
    process_line(line)

for _ in range(len(path.split("/")[0:-1])):
    process_line("$ cd ..")

sum = 0
for dir, size in dirs.items():
    if size <= 100000:
        sum += size

print(sum)
