package server;

import org.omg.CORBA.ORB;

import calculator_module.CalculatorPOA;

public class CalculatorImpl extends CalculatorPOA {

    private ORB orb;

    public void setORB(ORB orb_val) {

        orb = orb_val;

    }

    // implement add() method

    @Override

    public int add(int a, int b) {

        return a + b;

    }

    // implement subtract() method

    @Override

    public int subtract(int a, int b) {

        return a - b;

    }

    // implement multiply() method

    @Override

    public int multiply(int a, int b) {

        return a * b;

    }

    // implement divide() method

    @Override

    public int divide(int a, int b) {

        return a / b;

    }

    // implement shutdown() method

    @Override

    public void shutdown() {

        orb.shutdown(false);

    }

}