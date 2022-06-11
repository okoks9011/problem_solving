package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

type state struct {
	idx, bettery, acc int
}

func main() {
	var n, bMax, aMax int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &bMax)
	fmt.Fscan(in, &aMax)

	s := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Fscan(in, &s[i])
	}

	robot := state{
		idx:     0,
		bettery: bMax,
		acc:     aMax,
	}
	for {
		if robot.idx == n {
			break
		}
		if robot.acc == 0 && robot.bettery == 0 {
			break
		}

		if robot.acc == 0 {
			robot.bettery--
			if s[robot.idx+1] == 1 {
				robot.acc++
			}
		} else if robot.bettery == 0 {
			robot.acc--
		} else if robot.acc < aMax && s[robot.idx+1] == 1 {
			robot.bettery--
			robot.acc++
		} else {
			robot.acc--
		}
		robot.idx++
	}
	fmt.Println(robot.idx)
}
