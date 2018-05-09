function Unary (arg, apply, type) {
    this.arg = arg, this.apply = apply, this.type = type;
    this.evaluate = function (x, y, z) {
        return apply(arg.evaluate(x, y, z));
    };
    this.toString = function () {
        return this.arg.toString() + this.type;
    }
};


function Variable (name) {
    this.name = name;
    this.evaluate =  function (x, y, z) {
        switch (name) {
            case 'x': {
                return x;
            }
            case 'y': {
                return y;
            }
            case 'z': {
                return z;
            }
            default: {
                return -1;
            }
        }
    }
    this.toString = function () {
        return this.name;
    }
};

function Const (value) {
    this.value = value;
    this.evaluate = function () {
        return value;
    }
    this.toString = function () {
        return this.value.toString();
    }
};

function Negate (arg) {
    return new Unary(arg, function(x) {return -x; }, " negate");
}

function Square (arg) {
    return new Unary(arg, function(x) {return Math.pow(x, 2); }, " square");
}

function Sqrt (arg) {
    return new Unary(arg, function(x) {return Math.sqrt(Math.abs(x)); }, " sqrt");
}

function Binary (left, right, apply, type) {
    this.left = left, this.right = right, this.apply = apply, this.type = type;
    this.evaluate = function (x, y, z) {
        return apply(left.evaluate(x, y, z),
            right.evaluate(x, y, z));
    };
    this.toString = function () {
        return this.left.toString() + " " +
            this.right.toString() + " " + this.type;
    }
};

function Add (left, right) {
    return new Binary(left, right, function(x, y) {return x + y; }, "+");
}

function Subtract (left, right) {
    return new Binary(left, right, function(x, y) {return x - y; }, "-");
}

function Multiply (left, right) {
    return new Binary(left, right, function(x, y) {return x * y; }, "*");
}

function Divide (left, right) {
    return new Binary(left, right, function(x, y) {return x / y; }, "/");
}


//var expr = Square(Subtract(Variable('x'), Variable('y')));
//console.log(expr(3, 4));