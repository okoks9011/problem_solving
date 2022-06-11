package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func main() {
	var s string
	fmt.Fscan(in, &s)

	if len(s)%2 != 0 {
		fmt.Println("No")
		return
	}

	var stack []rune
	for _, si := range s {
		if len(stack) > 0 && stack[len(stack)-1] == si {
			stack = stack[:len(stack)-1]
			continue
		}
		stack = append(stack, si)
	}

	if len(stack) == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
