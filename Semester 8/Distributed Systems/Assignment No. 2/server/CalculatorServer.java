package server;

import org.omg.CORBA.ORB;

import org.omg.CosNaming.*;

import org.omg.PortableServer.*;

import calculator_module.Calculator;

import calculator_module.CalculatorHelper;

public class CalculatorServer {

    public static void main(String args[]) {

        try {

            // create and initialize the ORB

            ORB orb = ORB.init(args, null);

            // get reference to rootpoa & activate the POAManager

            POA rootpoa = (POA) orb.resolve_initial_references("RootPOA");

            rootpoa.the_POAManager().activate();

            // create servant and register it with the ORB

            CalculatorImpl calculatorImpl = new CalculatorImpl();

            calculatorImpl.setORB(orb);

            // get object reference from the servant

            org.omg.CORBA.Object ref = rootpoa.servant_to_reference(calculatorImpl);

            Calculator href = CalculatorHelper.narrow(ref);

            // get the root naming context

            // NameService invokes the transient name service

            org.omg.CORBA.Object objRef = orb.resolve_initial_references("NameService");

            // Use NamingContextExt which is part of the Interoperable

            // Naming Service (INS) specification.

            NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);

            // bind the Object Reference in Naming

            String name = "Calculator";

            NameComponent path[] = ncRef.to_name(name);

            ncRef.rebind(path, href);

            System.out.println("CalculatorServer ready and waiting ...");

            // wait for invocations from clients

            orb.run();

        } catch (Exception e) {

            System.err.println("ERROR: " + e);

            e.printStackTrace(System.out);

        } finally {

            System.out.println("CalculatorServer Exiting ...");

        }

    }

}