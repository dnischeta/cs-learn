const dir = [
  [-1, 0],
  [1, 0],
  [0, -1],
  [0, 1],
];

function walk(maze, wall, current, end, seen, path) {
  if (current.x < 0 || current.x >= maze[0].length || current.y < 0 || current.y >= maze.length) {
    return false;
  }

  if (maze[current.y][current.x] === wall) {
    return false;
  }

  if (current.x === end.x && current.y === end.y) {
    path.push(end);
    return true;
  }

  if (seen[current.y][current.x]) {
    return false;
  }

  // Recursion steps:
  // - pre
  // - recurse
  // - post
  seen[current.y][current.x] = true;
  path.push(current);

  for (let i = 0; i < dir.length; i++) {
    const [dx, dy] = dir[i];
    if (walk(maze, wall, { x: current.x + dx, y: current.y + dy }, end, seen, path)) {
      return true;
    }
  }

  path.pop();

  return false;
}

export function solve(maze, wall, start, end) {
  const seen = [];

  for (let i = 0; i < maze.length; i++) {
    seen[i] = new Array(maze[i].length).fill(false);
  }

  const path = [];

  walk(maze, wall, start, end, seen, path);

  return path;
}

