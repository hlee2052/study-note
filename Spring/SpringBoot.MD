# Spring Boot Note

## Prerequisites

### Classpath
###Inversion of Control
- process in which object defines its dependencies without creating them
###Dependency Injection


## Annotations

###@Bean
- a bean is object that is **instantiate**, **assembled**, and managed by a Spring IoC
- annotation explicitly declares a **single** bean  
- bean is for **method level**
- requires **@Component** annotation (whereas **@Component** is at **class level**)

```java
// can be useful for calling specific implementation based on some sate.
@Component
public class SomeServiceClass {

  @Bean
  public SomeService getService() {
    switch (state) {
      case 1:
        return new Impl1();
      case 2:
        return new Impl2();
      default:
        return new Impl();
    }
  }
}

// beans can be named
@Bean(name = "cat") 
public Cat getCat() ...
```

### @Configuration
- marker indicate class has 1 or more @Bean methods

### @EnableAutoConfiguration
- enable Spring to guess the configurations based on **included** jar and **classpath**
- automatically create/register beans based on **included** jar and **classpath**
- examples
    - If HSQLDB is on classpath, and if you did not manually configure db connection bean, then Spring will 
    automatically configure in-memory db

### @ComponentScan
- tell Spring to look for other **components**, **configurations** and **services** in the specified
package.
- Spring can auto scan all classes annotated with **@Component**, **@Controller**,
  **@Service**, and **@Repository**
  
### @Component
- generic stereotype for Spring managed component
- mark bean as managed component.
- Spring picks up and register beans with @Component
- **@Service** and **@Repository** are special cases of **@Component**


### @SpringBootApplication
- uses all of:
    - @Configuration
    - @EnableAutoConfiguration
    - @ComponentScan