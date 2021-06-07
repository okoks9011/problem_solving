package main

import (
	"bufio"
	"fmt"
	"os"
)

func Solve() {
	reader := bufio.NewReader(os.Stdin)
	text, _ := reader.ReadString('\n')
	fmt.Println(text)
}

func main() {
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		Solve()
	}
}
