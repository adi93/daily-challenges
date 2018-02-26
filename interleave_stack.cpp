#include<queue>
#include<stack>
#include<iostream>

void interleaveStack(std::stack<int>& s) {
	
	
        std::queue<int> q;
	int halfSize = s.size() / 2;
	bool odd = s.size() % 2;
	// q: [], s: 1(t) 2 3 4 5 6 7
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}
	// q: 7 6 5 4 3 2 1, s: []
	for (int i=0; i< halfSize; i++) {
		s.push(q.front());
		q.pop();
	}
	// q: 7 6 5 4, s: 3(t) 2 1
	if (odd) {
		q.push(q.front());
		q.pop();
	}
	// q: 4 7 6 5, s: 3(t) 2 1
	while (!s.empty()) {
		q.push(q.front());
		q.pop();
		q.push(s.top());
		s.pop();
	}
	// q: 1 7 2 6 3 5 4, s: []
	while (!q.empty()) {
		s.push(q.front());
		q.pop();
	}
}

int main() {
    std::stack<int> s;
    s.push(7);
    s.push(6);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
	// s is : 1(t) 2 3 4 5 6
	// we want: 1(t) 6 2 5 3 4
    interleaveStack(s);
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
	std::cout << std::endl;
    return 0;
}
