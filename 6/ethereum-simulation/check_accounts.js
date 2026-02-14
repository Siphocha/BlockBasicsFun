// File: check_accounts.js 
const { Web3 } = require('web3'); 
const web3 = new Web3('http://127.0.0.1:8545'); 
async function checkAccounts() { 
 console.log('\n=== ETHEREUM ACCOUNT CHECK ===\n');   // Get all accounts 
 const accounts = await web3.eth.getAccounts(); 
 console.log(`Total Accounts: ${accounts.length}\n`);   // Display first 3 accounts with balances 
 for (let i = 0; i < 3; i++) { 
 const balance = await web3.eth.getBalance(accounts[i]);  const ethBalance = web3.utils.fromWei(balance, 'ether');  console.log(`Account ${i}:`); 
 console.log(` Address: ${accounts[i]}`); 
 console.log(` Balance: ${ethBalance} ETH\n`);  } 
  // Get current block number 
 const blockNumber = await web3.eth.getBlockNumber();  console.log(`Current Block Number: ${blockNumber}`); } 
checkAccounts() 
 .then(() => process.exit(0)) 
 .catch(error => { 
 console.error('Error:', error); 
 process.exit(1); 
 }); 
