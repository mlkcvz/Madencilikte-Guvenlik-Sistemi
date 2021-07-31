import React from 'react';
import { ImageBackground, StyleSheet, Text, TextInput, View, Alert, TouchableOpacity, ActivityIndicator } from 'react-native';
import * as firebase from "firebase";
import { NavigationContainer, StackActions } from '@react-navigation/native';


export default class Physical extends React.Component{

  state = {
    datas : [],
    user: '',
    loading: false,
    co2: 0,
    co:0,
    o2:0,
    ch4:0,
    tempature:0,
    pressure:0,
    humidity:0
  }

  componentDidMount = () => {
    firebase.database().ref('co2').limitToLast(1).on('value', (snap) => {
      let datas = []
      snap.forEach((item) => {
        const { data, timestamp } = item.val();
        datas.push({ data, timestamp });
      });
      
      this.setState({ co2: datas[0].data });
    })

    firebase.database().ref('co').limitToLast(1).on('value', (snap) => {
      let datas = []
      snap.forEach((item) => {
        const { data, timestamp } = item.val();
        datas.push({ data, timestamp });
      });
      this.setState({ co: datas[0].data });
    })

    firebase.database().ref('o2').limitToLast(1).on('value', (snap) => {
      let datas = []
      snap.forEach((item) => {
        const { data, timestamp } = item.val();
        datas.push({ data, timestamp });
      });
      this.setState({ o2: datas[0].data });
    })

    firebase.database().ref('ch4').limitToLast(1).on('value', (snap) => {
      let datas = []
      snap.forEach((item) => {
        const { data, timestamp } = item.val();
        datas.push({ data, timestamp });
      });
      this.setState({ ch4: datas[0].data });
    })

    firebase.database().ref('temperature').limitToLast(1).on('value', (snap) => {
      let datas = []
      snap.forEach((item) => {
        const { data, timestamp } = item.val();
        datas.push({ data, timestamp });
      });
      this.setState({ tempature: datas[0].data });
    })


    firebase.database().ref('pressure').limitToLast(1).on('value', (snap) => {
      let datas = []
      snap.forEach((item) => {
        const { data, timestamp } = item.val();
        datas.push({ data, timestamp });
      });
      this.setState({ pressure: datas[0].data });
    })

    firebase.database().ref('humidity').limitToLast(1).on('value', (snap) => {
      let datas = []
      snap.forEach((item) => {
        const { data, timestamp } = item.val();
        datas.push({ data, timestamp });
      });
      this.setState({ humidity: datas[0].data });
    })






  } 
  goHome = () => {
    const popAction = StackActions.pop(1);
    this.props.navigation.dispatch(popAction);
  }
  render(){
    return(
      <View style={styles.containerw}>
      <View style={{flex:1, justifyContent:'space-evenly', alignItems:'baseline'}}>
      <View style={styles.panel}>
        <Text>CO2      :   {this.state.co2} </Text></View>
        <View style={styles.panel}>
      <Text>CO       :   {this.state.co}</Text></View>
      <View style={styles.panel}>
      <Text>O2       :   {this.state.o2}</Text></View>
      <View style={styles.panel}>
      <Text>CH4      :   {this.state.ch4}</Text></View>
      <View style={styles.panel}>
      <Text>Sıcaklık :   {this.state.tempature}</Text></View>
      <View style={styles.panel}>
      <Text>Basınç   :   {this.state.pressure}</Text></View>
      <View style={styles.panel}>
      <Text>Nem      :   {this.state.humidity}</Text></View>
      </View>
      <TouchableOpacity style={styles.homeButton} onPress = {() => (this.goHome())}>
       
            <Text style={styles.homeButtonText}>
                Home
            </Text>
         
      </TouchableOpacity>
      </View>
      
    );
  }
}
const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#008b8b",
    alignItems: "center",
    justifyContent: "center",
  },
  containerw: {
    flex: 1,
    backgroundColor: "#008b8b",
    alignItems: "center",
    justifyContent: "center",
  },
 
  homeButton: {
    width: "70%",
    borderRadius: 25,
    height: 45,
    alignItems: "center",
    justifyContent: "center",
    marginTop: 40,
    backgroundColor: "#00003f",
    marginBottom:5,
  },
  homeButtonText : {
    color : "#f8fcfd",
    fontWeight: "bold",
  },
  panel: {
    height: "8%", 
    width: "100%",
    backgroundColor:'#FBFAF5', 
    flexDirection: 'row', 
    alignItems: 'center', 
    borderRadius: 9,
    justifyContent: 'space-evenly',
    borderColor: "#00003f",
    borderWidth:4,
  },
});