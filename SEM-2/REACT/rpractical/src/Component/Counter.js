import React,{Component} from 'react'

class Counter extends Component{

    constructor(props){
        super(props);
        this.state={count:0};
    }

    incrementCount  =()=>{
        this.setState({count:this.state.count+1});
    };

    render()
    {
        return(
            <div>
                <center>
                <h2>Counter:{this.state.count}</h2>
                <button onClick={this.incrementCount}>Increment</button>
                </center>
            </div>
        );
    }
   

}

export default Counter;
