#database

## Source
[How to interpret SQL Server errors? - Stack Overflow](https://stackoverflow.com/questions/53985809/how-to-interpret-sql-server-errors)

## Content
- **Error number**  
    Each error message has a unique error number.
- **Error message string**  
    The error message contains `diagnostic information about the cause of the error`. Many error messages have substitution variables in which information, such as the name of the object generating the error, is inserted.
- **Severity** The severity indicates how serious the error is. Errors that have a low severity, such as 1 or 2, are information messages or low-level warnings. `Errors that have a high severity indicate problems that should be addressed as soon as possible`.
- **State**  
    Some error messages can be raised at multiple points in the code for the Database Engine. For example, an 1105 error can be raised for several different conditions. Each specific condition that raises an error assigns a unique state code.
    
    When you are viewing databases that contain information about known issues, such as the Microsoft Knowledge Base, you can use the state number to determine whether the recorded issue is the same as the error you have encountered. [...]
- **Procedure name**  
    Is the name of the stored procedure or trigger in which the error has occurred.
- **Line number**  
    Indicates which statement in a batch, stored procedure, trigger, or function generated the error.


`[Batch Start Line 57]` means that you are running a script with multiple batches - (if it's in SSMS the batches are separated by the `GO` keyword) - so the error is in the 3rd line of the batch that starts in line 57 of the script.