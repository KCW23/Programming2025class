#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLOORS 20
#define MAX_REQ 1000
#define SIM_TIME 1000
#define DOOR_TIME 2

typedef struct {
    int floor;
    int time;
    int direction; // 1 up, -1 down, 0 inside
    bool active;
} Request;

Request up_list[MAX_REQ];
Request down_list[MAX_REQ];
Request inside_list[MAX_REQ];

void init_list(Request list[]) {
    for (int i = 0; i < MAX_REQ; i++) {
        list[i].active = false;
    }
}

void add_request(Request list[], int floor, int time, int dir) {
    for (int i = 0; i < MAX_REQ; i++) {
        if (!list[i].active) {
            list[i].floor = floor;
            list[i].time = time;
            list[i].direction = dir;
            list[i].active = true;
            return;
        }
    }
}

bool exists_floor(Request list[], int floor) {
    for (int i = 0; i < MAX_REQ; i++) {
        if (list[i].active && list[i].floor == floor)
            return true;
    }
    return false;
}

void remove_floor(Request list[], int floor) {
    for (int i = 0; i < MAX_REQ; i++) {
        if (list[i].active && list[i].floor == floor) {
            list[i].active = false;
            return;
        }
    }
}

int nearest_target(int current_floor) {
    int best_floor = -1;
    int min_diff = 999;
    Request* lists[3] = { up_list, down_list, inside_list };

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < MAX_REQ; i++) {
            if (lists[k][i].active) {
                int diff = abs(lists[k][i].floor - current_floor);
                if (diff < min_diff) {
                    min_diff = diff;
                    best_floor = lists[k][i].floor;
                }
            }
        }
    }
    return best_floor;
}

int main(void) {
    srand((unsigned)time(NULL));

    init_list(up_list);
    init_list(down_list);
    init_list(inside_list);

    int N = 10;
    int elevator_floor = 1;
    int direction = 0;
    int door_timer = 0;

    int total_requests = 0;   // 외부 호출 수 (승객 수)
    int completed_requests = 0; // 목적지에 도달한 승객 수

    for (int t = 0; t < SIM_TIME; t++) {

        // 외부 호출 생성 (랜덤)
        if (rand() % 10 < 2) {
            int floor = (rand() % N) + 1;
            int dest = (rand() % N) + 1;
            while (dest == floor)
                dest = (rand() % N) + 1;

            int dir = (dest > floor) ? 1 : -1;
            if (dir == 1)
                add_request(up_list, floor, t, dir);
            else
                add_request(down_list, floor, t, dir);

            total_requests++;
        }

        // 문이 열려 있는 동안 정지
        if (door_timer > 0) {
            door_timer--;
            continue;
        }

        bool stopped = false;

        // (1) 내부 목적지에 도달했을 때 -> 승객 완료
        if (exists_floor(inside_list, elevator_floor)) {
            remove_floor(inside_list, elevator_floor);
            completed_requests++;   // 여기서만 완료 카운트 증가
            stopped = true;
        }

        // (2) 외부 호출(승객 탑승) 처리: 탑승 시에는 completed_requests 증가시키지 않음
        if (exists_floor(up_list, elevator_floor)) {
            remove_floor(up_list, elevator_floor);
            int dest = (rand() % N) + 1;
            while (dest == elevator_floor)
                dest = (rand() % N) + 1;
            add_request(inside_list, dest, t, 0); // 탑승자가 누른 목적지
            stopped = true;
        }

        if (exists_floor(down_list, elevator_floor)) {
            remove_floor(down_list, elevator_floor);
            int dest = (rand() % N) + 1;
            while (dest == elevator_floor)
                dest = (rand() % N) + 1;
            add_request(inside_list, dest, t, 0);
            stopped = true;
        }

        if (stopped) {
            door_timer = DOOR_TIME;
            continue;
        }

        // (3) idle이면 가장 가까운 요청으로 방향 설정
        if (direction == 0) {
            int target = nearest_target(elevator_floor);
            if (target != -1) {
                if (target > elevator_floor) direction = 1;
                else if (target < elevator_floor) direction = -1;
            }
        }

        // (4) 이동
        if (direction == 1) elevator_floor++;
        else if (direction == -1) elevator_floor--;

        // 경계 처리
        if (elevator_floor <= 1) {
            elevator_floor = 1;
            direction = 1;
        }
        if (elevator_floor >= N) {
            elevator_floor = N;
            direction = -1;
        }

        // 주기 출력
        if (t % 50 == 0) {
            printf("t=%d floor=%d dir=%d\n", t, elevator_floor, direction);
        }
    }

    // 시뮬레이션 종료 시 남아있는 inside_list 처리(선택 사항)
    // 여기서는 시뮬레이션 종료 시점까지 실제 목적지에 도달한 수만 completed_requests에 반영되어 있음.

    printf("Total external requests (passengers) = %d\n", total_requests);
    printf("Completed (reached destination) = %d\n", completed_requests);
    printf("Pending (not completed) = %d\n", total_requests - completed_requests);

    return 0;
}
