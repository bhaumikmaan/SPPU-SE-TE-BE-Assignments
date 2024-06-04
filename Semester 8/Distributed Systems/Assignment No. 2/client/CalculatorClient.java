package client;

import org.omg.CORBA.ORB;

import org.omg.CORBA.ORBPackage.InvalidName;

import org.omg.CosNaming.*;

import calculator_module.Calculator;

import calculator_module.CalculatorHelper;

public class CalculatorClient {

    public static void main(String args[]) {

        try {

            // create and initialize the ORB

            ORB orb = ORB.init(args, null);

            // get the root naming context

            // NameService invokes the transient name service

            org.omg.CORBA.Object objRef = orb.resolve_initial_references("NameService");

            // Use NamingContextExt which is part of the Interoperable

            // Naming Service (INS) specification.

            NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);

            // resolve the Object Reference in Naming

            String name = "Calculator";

            Calculator calculator = CalculatorHelper.narrow(ncRef.resolve_str(name));

            System.out.println("Obtained a handle on server object");

            System.out.println(calculator.add(1, 2));

            System.out.println(calculator.subtract(1, 2));

            System.out.println(calculator.multiply(1, 2));

            System.out.println(calculator.divide(1, 2));

        } catch (Exception e) {

            System.out.println("ERROR : " + e);

            e.printStackTrace(System.out);

        }

    }

}