
'''
1. Read Maze --> 2-dim array
2. Search: AStar
    2-1. Initialize: Set Start, Goal, Heuristic Cost Value(기울어진 운동장, h)
            , Openlist( {해당 노드의 좌표, f(토탈비용함수) = g(비용함수)+h(휴리스틱), g} )에 start 지점의 정보 담아주기
    While:
        2-2. Cell sort in Open lists:
        2-3. Pick the next node (the lowest cost value)
        2-4. Add to Open lists (이웃 노드들, 현재 노드에서 방문할 수 있는 주변 노드 <위, 아래, 좌, 우>)
            - 근데 방문 후보지는 장애물이어선 안되고, 맵 바깥이어도 안되고, 기 방문한 곳도 안된다.

        if (현재 node=goal)
            found, break
        if (더이상 opens에 방문할 수 있는 곳이 없을떈)
            resign, break
        
3. Print Solution
    - 답을 출력하기 위해 이동 경로를 스텝마다 저장할 수 있는 array를 생성할 것 : -> navigtion
'''

import numpy as np

class ReadMaze:
    def __init__(self, _file):
        self.f = open(_file, 'r')
        self.maze = list()
        self.start_point = [-1,-1]
        self.goal_point = [-1,-1]

        row = 0
        while True:
            file_line = self.f.readline()
            
            if not file_line:
                break    

            line = list()
            col =0
            for char in file_line:
                
                if (char is 'S'):
                    self.start_point = [row, col]
                if (char == 'G'):
                    self.goal_point = [row, col]
                if (char is not '\n'):
                    line.append(char)
                
                col+=1
            row+=1
            self.maze.append(line)

        self.f.close()

class Search:
    def __init__(self, _start, _goal, _maze):
        self.start = _start
        self.goal = _goal
        self.maze = _maze

        self.heuristic_map = list()
        for row, value in enumerate(self.maze):
            heuristic_row = list()
            for col, _ in enumerate(value):
                heuristic_row.append(self.heuristic_calculate([row, col], self.goal))
            self.heuristic_map.append(heuristic_row)

        self.opens = list()
        
        g = 0
        h = self.heuristic_map[self.start[0]][self.start[1]]
        f = g+h
        self.opens= [[f, g, self.start]] # 시작지점이니까!
        self.closed = [self.start]


    def heuristic_calculate(self, current_node, goal_node):
        return abs(goal_node[0]-current_node[0]) + abs(goal_node[1]-current_node[1])

    def searh_step(self):
        self.navigation = [[0 for col in range(len(self.maze[0]))] for row in range(len(self.maze))] # 맵의 사이즈만큼 0으로 채운 배열


        self.delta = [[0, 1], [0, -1], [1,0], [-1,0]] # [row, col]: 오른쪽, 왼쪽, 아래, 위

        resign = False # 끝내 미로를 찾을 수 없을 때, True
        found = False # 도착지점에 다달으면 True


        count = 0
        while(resign == False and found == False):
            count += 1

            self.opens.sort(key = lambda x: x[0], reverse=True) # 내림차순 정렬, 즉 낮은애가 맨 뒤 # Cell sort in Open lists:

            current = self.opens.pop() # 제일 낮은애가 뽑힘 # Pick the next node (the lowest cost value)
            
            current_node = current[2]
            current_g = current[1]

            if( current_node[0] == self.goal[0] and current_node[1] == self.goal[1] ):
                found = True
                print("FIND WAY", f"최단거리: {current_g}")
                self.print_solution(self.start, self.goal)

            
            else:
                #현재 노드에서 방문할 수 있는 좌표를 탐색하는 것# Add to Open lists
                for idx, d in enumerate(self.delta): 
                    row = current_node[0] + d[0]
                    col = current_node[1] + d[1]

                    if (self.maze[row][col] is not '#' and row >= 0 and row < len(self.maze) and col >=0 and col < len(self.maze[0])): # 미로에 닿으면 안되고, 맵을 벗어나서도 안됨

                        if not ([row,col] in self.closed): # 방문하지 않은 곳만 방문해!
                            g = current_g + 1 # 비용함수를 1 증가
                            
                            f = g + self.heuristic_map[row][col]
                            neighbor_node = [row, col]
                            self.closed.append(neighbor_node)
                            self.opens.append([f, g, neighbor_node])

                            self.navigation[row][col] = idx # 방향을 저장함

            if (len(self.opens)==0): # opens가 텅 비어있다면, 경로는 없다는 의미다.!
                resign=True
                print("NO WAY")


    def print_solution(self, start, goal):
        #self.delta = [[0, 1], [0, -1], [1,0], [-1,0]] # [row, col]: 오른쪽, 왼쪽, 아래, 위
        next_node = goal
        self.printer = [[0 for col in range(len(self.maze[0]))] for row in range(len(self.maze))]

        while (next_node[0] != start[0] or next_node[1] != start[1]):
            if self.navigation[next_node[0]][next_node[1]] == 0: #오른쪽
                self.printer[next_node[0]][next_node[1]] = '>'
                next_node[0] = next_node[0] - self.delta[0][0]
                next_node[1] = next_node[1] - self.delta[0][1]

            elif self.navigation[next_node[0]][next_node[1]] == 1: #왼쪽
                self.printer[next_node[0]][next_node[1]] = '<'
                next_node[0] = next_node[0] - self.delta[1][0]
                next_node[1] = next_node[1] - self.delta[1][1]

            elif self.navigation[next_node[0]][next_node[1]] == 2: #아래
                self.printer[next_node[0]][next_node[1]] = 'v'
                next_node[0] = next_node[0] - self.delta[2][0]
                next_node[1] = next_node[1] - self.delta[2][1]

            
            elif self.navigation[next_node[0]][next_node[1]] == 3: #위
                self.printer[next_node[0]][next_node[1]] = '^'
                next_node[0] = next_node[0] - self.delta[3][0]
                next_node[1] = next_node[1] - self.delta[3][1]

        print(self.printer)
        ##################################
        # 파일이 너무 커서 출력하려고 만든 함수
        import csv
        with open('answer.csv','a',newline='') as f:
            writer = csv.writer(f)
            for row in self.printer:
                writer.writerow(row)
        ##################################

if __name__== "__main__":
    Maze = ReadMaze("./maze.txt")
    Searcher = Search(Maze.start_point, Maze.goal_point, Maze.maze)
    Searcher.searh_step()
