var pi = function () {
    return Math.PI;
}

var e = function () {
    return Math.E;
}



// unary
var unary = function (apply) {
    return function (arg) {
        return function (x, y, z) {
            return apply(arg(x, y, z));
        };
    }
};

var variable = function (name) {
    return function (x, y, z) {
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
        }
    }
};

var x = variable('x');
var y = variable('y');
var z = variable('z');

var cnst = function (value) {
    return function (x) {
        return value;
    }
};

var negate = unary(
    function (arg) {
        return -arg;
    }
);

var cube = unary(
    function (arg) {
        return Math.pow(arg, 3);
    }
);

var cuberoot = unary(
    function (arg) {
        return Math.pow(arg, 1.0 / 3);
    }
);

// binary
var binary = function (apply) {
    return function (left, right) {
        return function (x, y, z) {
            return apply(left(x, y, z), right(x, y, z));
        };
    }
};

var add = binary(
    function (left, right) {
        return left + right;
    }
);

var subtract = binary(
    function (left, right) {
        return left - right;
    }
);

var multiply = binary(
    function (left, right) {
        return left * right;
    }
);

var divide = binary(
    function (left, right) {
        return left / right;
    }
);

var poly = function (apply) {
    return function() {
        var data = arguments;
        return function (x, y, z) {
            var ans = data[0](x, y, z);
            for(var i = 1; i < data.length; i++) {
                ans = apply(data[i](x, y, z), ans);
            }
            return ans;
        }
    }
};

var min3 = poly(
    function (left, right) {
        return Math.min(left, right);
    }
);

var max5 = poly(
    function (left, right) {
        return Math.max(left, right);
    }
);