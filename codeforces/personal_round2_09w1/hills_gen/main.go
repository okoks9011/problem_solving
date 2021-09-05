package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"strings"
)

func main() {
	f, err := os.Create("hills_gen")
	if err != nil {
		return
	}
	defer f.Close()

	t := 10
	w := bufio.NewWriter(f)
	w.WriteString(fmt.Sprintf("%d\n", t))
	for i := 0; i < t; i++ {
		c := rand.Intn(900) + 100
		w.WriteString(fmt.Sprintf("%d\n", c))

		var buf []string
		for j := 0; j < c; j++ {
			buf = append(buf, strconv.Itoa(rand.Intn(1000)))
		}
		w.WriteString(fmt.Sprintf("%s\n", strings.Join(buf, " ")))
	}
}
