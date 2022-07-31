package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

type optype int

const (
	ADD optype = iota + 1
	FOR
	END
)

type operation struct {
	t optype
	x int64
}

func main() {
	var n int
	fmt.Fscan(in, &n)

	var ops []operation
	for i := 0; i < n; i++ {
		var op string
		fmt.Fscan(in, &op)

		cur := operation{}
		switch op {
		case "add":
			cur.t = ADD
		case "for":
			cur.t = FOR
			fmt.Fscan(in, &cur.x)
		case "end":
			cur.t = END
		default:
			panic("impossible")
		}
		ops = append(ops, cur)
	}

	var int32Max int64 = 1<<32 - 1
	buf, multi := []int64{0}, []int64{1}
	for _, op := range ops {
		switch op.t {
		case ADD:
			buf[len(buf)-1]++
		case FOR:
			buf = append(buf, 0)
			multi = append(multi, op.x)
		case END:
			if len(buf) == 0 || len(multi) == 0 {
				panic("impossible")
			}
			succ := buf[len(buf)-1] * multi[len(multi)-1]
			buf = buf[:len(buf)-1]
			multi = multi[:len(multi)-1]

			buf[len(buf)-1] += succ
		default:
			panic("unknown op")
		}
		if buf[len(buf)-1] > int32Max {
			fmt.Println("OVERFLOW!!!")
			return
		}
	}
	if len(buf) != 1 || len(multi) != 1 {
		panic("invalid func")
	}
	fmt.Println(buf[0])
}
