import logo from './logo.svg';
import './App.css';
import HelloWorld from './Component/HelloWorld';
import Counter from './Component/Counter';
import Form from './Component/Form';
import DataFetcher from './Component/DataFetcher';
import ProgressBar from './Component/ProgressBar';

function App() {
  return (
   <div>
    <HelloWorld/>
    <Counter/>
    <Form/>
    <DataFetcher/>

    <div className="App">
      <h1>Progress Bar with Percentage</h1>
      <ProgressBar progress={30} color="#ff6f61" height="25px"  showLabel={true}/>
      <ProgressBar progress={60} color="#76c7c0" height="25px" showLabel={true}/> 
      <ProgressBar progress={50} color="#ffa500" height="25px" showLabel={true}/> 
      <ProgressBar progress={85} color="#4caf50" height="25px" showLabel={true}/> 
      <ProgressBar progress={95} color="#6a11cb" height="25px" showLabel={true}/> 
    </div>
   

   </div>
  );
}

export default App;
