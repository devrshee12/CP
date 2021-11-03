


// const userMethods = {

//     details : function(){
//         return `first name is ${this.firstName} last name is ${this.lastName} age is ${this.age}`;
//     },
//     sing : function(){
//         return 'i am singing';
//     }

// }

// function createUser(firstName, lastName, age){
//     const user = Object.create(userMethods);
//     user.firstName = firstName;
//     user.lastName = lastName;
//     user.age = age;
//     return user;


// }


// const user1 = createUser("Devarshee", "Panchhiwala", 17);
// const user2 = createUser("madhav", "Panchhiwala", 23);
// const user3 = createUser("shilpa", "Panchhiwala", 40);
// console.log(user1.__proto__);

// console.log(user1.details());
// console.log(user3.details());


//function prototype 




// function hello(){
//     console.log("hello world");
// }

// // hello();
// // console.log(hello.prototype);
// // hello.prototype.temp = function(){
// //     console.log("i am in hello function in that i am in prototype in that i define temp function");
// // };

// hello.prototype.temp = function(){
//     console.log("i am in hello function in that i am in prototype in that i define temp function");
// };

// // hello.prototype.temp();

// hello.prototype.firstName = "devarshee";

// // console.log(hello.prototype.firstName);
// console.log(hello.prototype);





// const userMethods = {

//     details : function(){
//         return `first name is ${this.firstName} last name is ${this.lastName} age is ${this.age}`;
//     },
//     sing : function(){
//         return 'i am singing';
//     }

// }

function createUser(firstName, lastName, age){
    const user = Object.create(createUser.prototype);
    user.firstName = firstName;
    user.lastName = lastName;
    user.age = age;
    createUser.prototype.details = function(){
        return `first name is ${this.firstName} last name is ${this.lastName} age is ${this.age}`;

    }
    createUser.prototype.sing = function(){
        return "lall lallala";
    }
    
    return user;


}


const user1 = createUser("Devarshee", "Panchhiwala", 17);
const user2 = createUser("madhav", "Panchhiwala", 23);
const user3 = createUser("shilpa", "Panchhiwala", 40);
// console.log(user1.__proto__);

console.log(user1.details());
console.log(user1.sing());
console.log(user1.__proto__);//if we dont find ant function or variable you can find here


console.log(createUser.prototype);//function gives you free space to create anything you want 
//you can create that in function prototype 




console.log(user3.details());
















































































































