# switch rule

1. **default case 可以依照任何順序放在 switch 裡**，會先比對完所有case才會跳到default
2. **default case 可以不存在**，若比對不到任何case，也沒有default case，則程式會離開switch{ }
3. **不同 case 可以對應到同一個陳述式(程式區段)**，如上方的case2跟case3，都是執行Console.WriteLine("Case 2或3");
4. **同一 case 不能對應到不同陳述式(程式區段)**
5. switch 陳述式中只會執行一個參數區段(一個case)。C#不允許從某個參數區段繼續執行至另一個參數區段。所以所有的參數區段都要使用 break、goto、throw或 return 陳述式明確地結束。

補充break、goto、throw、return

- `break`: 會跳出其所在的最接近封閉式迴圈(最接近的{ })或 `switch` 陳述式。
- `goto`:將程式控制權轉移到特定的標籤或 `switch` 的 `case`，也可以用來跳出深度巢狀的迴圈。
- `throw`:終止執行在其中出現的方法，並且將控制權傳回給呼叫方法。
- `return`:跳出最接近的函式，例如整個 `switch` 寫在main()這個方法裡，`return` 是跳出`main()` 而不只是跳出 `switch`。