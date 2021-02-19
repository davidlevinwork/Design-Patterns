# Design-Patterns
C++ Design Patterns Implementations.

### What can I find here?
Design Pattern
----- |
`Abstract Factory`  
`Factory`  
`Factory with Lambda expression` | 
`Factory with Prototype` | 
`Adapter` |
`Object Adapter` |
`Strategy` |
`Singleton` |
`Prototype` |
`Bridge` |
`Builder` |
`Decorator` | 
`Decorator Permanently` | 
`Composite acyclic` | 
`Proxy` | 


## Notes

**Composite acyclic:** 
- You cannot be a manager of an employee who already has a manager
- You can not be your manager's manager
- You can not be your own manager

**Decorator Permanently:** <br />
Enforcing an order ratio when creating the objects. <br />
The result will always be the same, regardless of the order in which the objests are inserted.

**Factory design**, Avoiding writing N cllasses for the factory objets: 
- Factory with Lambda expression
- Factory with Prototype

**Proxy:** <br />
Effective cache management. Prevents objects duplication and leads to vaccination on the complexity time.
