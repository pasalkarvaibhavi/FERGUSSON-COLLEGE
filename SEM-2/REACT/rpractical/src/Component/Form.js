import React, { Component } from 'react';

class Form extends Component {
    
    constructor(props) {
        super(props);
        this.state = { name: "", email: "" };
    }

    handleChange = (event) => {
        this.setState({ [event.target.name]: event.target.value });
    };

    handleSubmit = (event) => {
        event.preventDefault();
        alert(`Name: ${this.state.name}, Email: ${this.state.email}`); // Corrected alert syntax
    };

    render() {
        return (
            <center> 
                <form onSubmit={this.handleSubmit}>
                    <div>
                        <h1>Form</h1><br></br>
                        <label>Enter Name:</label>
                        <input type="text" name="name" value={this.state.name} onChange={this.handleChange} /><br></br><br></br>
                        <label>Enter Email:</label>
                        <input type="email" name="email" value={this.state.email} onChange={this.handleChange} /><br></br><br></br>
                    </div>
                    <button type="submit">Submit</button>
                </form>
            </center>
        );
    }
}

export default Form;